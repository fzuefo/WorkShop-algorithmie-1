#!/bin/bash


num1=2
num2=1
expected_result=$((num1 * num2))

# Execute the program and capture the first two lines of output
output=$(./a.out "$num1" "$num2" | tr -d '\0' | head -n 2)

# Read the two lines into variables
read -r line1 <<< "$(echo "$output" | sed -n '1p')"
read -r line2 <<< "$(echo "$output" | sed -n '2p')"

# Compare each line with the expected result
if [ "$line1" -eq "$expected_result" ] && [ "$line2" -eq "$expected_result" ]; then
    echo "Both lines match the expected product: $expected_result"
else
    echo "Mismatch detected!"
    echo "Expected: $expected_result"
    echo "Line 1: $line1"
    echo "Line 2: $line2"
fi

num1=9
num2=2
expected_result=$((num1 * num2))

# Execute the program and capture the first two lines of output
output=$(./a.out "$num1" "$num2" | tr -d '\0' | head -n 2)

# Read the two lines into variables
read -r line1 <<< "$(echo "$output" | sed -n '1p')"
read -r line2 <<< "$(echo "$output" | sed -n '2p')"

# Compare each line with the expected result
if [ "$line1" -eq "$expected_result" ] && [ "$line2" -eq "$expected_result" ]; then
    echo "Both lines match the expected product: $expected_result"
else
    echo "Mismatch detected!"
    echo "Expected: $expected_result"
    echo "Line 1: $line1"
    echo "Line 2: $line2"
fi


num1=9
num2=9
expected_result=$((num1 * num2))

# Execute the program and capture the first two lines of output
output=$(./a.out "$num1" "$num2" | tr -d '\0' | head -n 2)

# Read the two lines into variables
read -r line1 <<< "$(echo "$output" | sed -n '1p')"
read -r line2 <<< "$(echo "$output" | sed -n '2p')"

# Compare each line with the expected result
if [ "$line1" -eq "$expected_result" ] && [ "$line2" -eq "$expected_result" ]; then
    echo "Both lines match the expected product: $expected_result"
else
    echo "Mismatch detected!"
    echo "Expected: $expected_result"
    echo "Line 1: $line1"
    echo "Line 2: $line2"
fi

# Get the input numbers
num1=12
num2=12
expected_result=$((num1 * num2))

# Execute the program and capture the first two lines of output
output=$(./a.out "$num1" "$num2" | tr -d '\0' | head -n 2)

# Read the two lines into variables
read -r line1 <<< "$(echo "$output" | sed -n '1p')"
read -r line2 <<< "$(echo "$output" | sed -n '2p')"

# Compare each line with the expected result
if [ "$line1" -eq "$expected_result" ] && [ "$line2" -eq "$expected_result" ]; then
    echo "Both lines match the expected product: $expected_result"
else
    echo "Mismatch detected!"
    echo "Expected: $expected_result"
    echo "Line 1: $line1"
    echo "Line 2: $line2"
fi


num1=232
num2=115
expected_result=$((num1 * num2))

# Execute the program and capture the first two lines of output
output=$(./a.out "$num1" "$num2" | tr -d '\0' | head -n 2)

# Read the two lines into variables
read -r line1 <<< "$(echo "$output" | sed -n '1p')"
read -r line2 <<< "$(echo "$output" | sed -n '2p')"

# Compare each line with the expected result
if [ "$line1" -eq "$expected_result" ] && [ "$line2" -eq "$expected_result" ]; then
    echo "Both lines match the expected product: $expected_result"
else
    echo "Mismatch detected!"
    echo "Expected: $expected_result"
    echo "Line 1: $line1"
    echo "Line 2: $line2"
fi
