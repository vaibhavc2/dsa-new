// Competitive Programming / LeetCode Template in TypeScript

/** Utility function for fast input parsing */
function input(): string[] {
    return require("fs").readFileSync(0, "utf-8").trim().split("\n");
}

/** Custom print function for standard output */
function print(...args: unknown[]): void {
    console.log(args.join(" "));
}

/** Custom debugging */
const DEBUG = false;
function debug(...args: unknown[]): void {
    if (DEBUG) console.error("DEBUG:", ...args);
}


/** Utility function to parse integers from space-separated strings */
function parseLine(line: string): number[] {
    return line.split(" ").map(Number);
}

/** Main solve function: implement problem logic here */
function solve(lines: string[]): void {
    const t = parseInt(lines[0], 10); // Number of test cases

    for (let i = 1; i <= t; i++) {
        const data = parseLine(lines[i]); // Parse each test case
        // Example: print the sum of numbers in each test case
        print(data.reduce((a, b) => a + b, 0));
    }
}

/** Main function to handle execution */
function main(): void {
    const lines = input();

    const isSingleTestCase = true; // Set to false if multiple test cases exist

    if (isSingleTestCase) {
        solve(lines); // For single test case
    } else {
        const testCaseCount = parseInt(lines[0], 10);
        let currentLine = 1;
        for (let i = 0; i < testCaseCount; i++) {
            const subLines = lines.slice(currentLine, currentLine + 1); // Adjust as per problem
            solve(subLines);
            currentLine += subLines.length;
        }
    }
}

main();
