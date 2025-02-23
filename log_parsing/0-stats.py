#!/usr/bin/python3
"""
Reads stdin line by line and computes metrics.
"""

import sys

if __name__ == "__main__":
    status_codes = {"200": 0, "301": 0, "400": 0, "401": 0,
                    "403": 0, "404": 0, "405": 0, "500": 0}
    total_size = 0
    line_count = 0

    def print_stats():
        """Prints accumulated metrics."""
        print(f"File size: {total_size}")
        for code in sorted(status_codes.keys()):
            if status_codes[code] > 0:
                print(f"{code}: {status_codes[code]}")

    try:
        for line in sys.stdin:
            parts = line.split()
            if len(parts) >= 9:
                try:
                    status_code = parts[-2]
                    file_size = int(parts[-1])
                    
                    if status_code in status_codes:
                        status_codes[status_code] += 1
                    
                    total_size += file_size
                except ValueError:
                    continue
            
            line_count += 1
            if line_count % 10 == 0:
                print_stats()
    except KeyboardInterrupt:
        print_stats()
        raise
    
    print_stats()
