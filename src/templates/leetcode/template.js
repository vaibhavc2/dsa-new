// Competitive Programming / LeetCode Template in JavaScript

/** Utility function for fast input parsing */
function input() {
    return require("fs").readFileSync(0, "utf-8").trim().split("\n");
}

/** Custom print function for standard output */
function print(...args) {
    console.log(...args.join(" "));
}

/** Custom debugging */
const DEBUG = false;
function debug(...args) {
    if (DEBUG) console.error("DEBUG:", ...args);
}


/** Utility function to parse integers from space-separated strings */
function parseLine(line) {
    return line.split(" ").map(Number);
}

/** Main solve function: implement problem logic here */
function solve(lines) {
    // Example input parsing, replace with problem-specific code
    const t = parseInt(lines[0], 10); // Number of test cases

    for (let i = 1; i <= t; i++) {
        // Process each test case
        const data = parseLine(lines[i]);
        // Perform operations based on `data`
        // Example: print the sum of numbers
        print(data.reduce((a, b) => a + b, 0));
    }
}

/** Main function to handle execution */
function main() {
    const lines = input();

    const isSingleTestCase = true; // Set to false if multiple test cases exist

    if (isSingleTestCase) {
        solve(lines); // For single test case
    } else {
        const testCaseCount = parseInt(lines[0], 10);
        let currentLine = 1;
        for (let i = 0; i < testCaseCount; i++) {
            const subLines = lines.slice(currentLine, currentLine + 1); // Adjust based on input structure
            solve(subLines);
            currentLine += subLines.length;
        }
    }
}

main();
