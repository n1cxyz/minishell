#!/bin/bash

# Path to the history file
HISTORY_FILE="./test_history.txt"
# program to test for
PROGRAMM="./minishell"
# If no arguments are passed, show usage instructions
if [[ $# -eq 0 ]]; then
    echo "Usage: ./tester.sh [new_test_arguments | --replay]"
    echo "new_test_arguments : Run a new test and save it to history"
    echo "--replay : Replay all tests from history"
    exit 1
fi
# Function to run a test and append it to the history file
run_test() {
    command="$PROGRAMM \"$1\""
    echo "Running: $command"
    eval $command

    # Remove any previous occurrence of the command to avoid duplicates
    remove_duplicates "$command"

    # Prepend the command to the top of the stack (history file)
    echo "$command" | cat - "$HISTORY_FILE" > temp && mv temp "$HISTORY_FILE"
}
# Function to remove duplicate entries of a test from the stack
remove_duplicates() {
    # Remove any existing lines that match the command
    grep -v -F "$1" "$HISTORY_FILE" > temp && mv temp "$HISTORY_FILE"
}
# Function to replay tests from the stack (most recent first)
replay_tests() {
    if [[ ! -f "$HISTORY_FILE" ]]; then
        echo "No history file found."
        exit 1
    fi

    # Read the history file and run commands in order (newest to oldest)
    while IFS= read -r line; do
        echo "Re-running: $line"
        eval $line
    done < "$HISTORY_FILE"
}
# Check if the user wants to replay tests
if [[ $1 == "--replay" ]]; then
    replay_tests
else
    # Treat all arguments as part of a new test
    run_test "$*"
fi
