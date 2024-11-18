# Kronos InTouch Clock Log Analyzer

## Overview
This project analyzes Kronos InTouch clock logs to verify server boot events and calculate elapsed times. It uses regular expressions for parsing log data and outputs results to a `.rpt` file.

## Features
- **Log Processing:** Reads log entries line-by-line from standard input.
- **Event Detection:** Identifies server start and completion events using regular expressions.
- **Elapsed Time Calculation:** Computes and logs the duration between server start and completion.
- **Output Results:** Writes events and calculated times to `device[1-6]_intouch.log.rpt` and the console.

## How It Works
1. **Input:** The program reads log data line-by-line from standard input.
2. **Regex Matching:** 
   - Extracts timestamps.
   - Detects "server started" and "server completion" log messages.
3. **Event Tracking:**
   - Logs server start times.
   - Calculates and logs elapsed times between start and completion events.
4. **Failure Handling:** Logs "failure" if a server fails to complete before the end of input.

## Compilation
Compile the program with the Boost.Regex library:
```bash
g++ stdin_boost.cpp -lboost_regex
```
## Run the program
cat log_file.log | ./a.out

## For questions or feedback, contact:
Noah Fay
Email: noahfay43@gmail.com
