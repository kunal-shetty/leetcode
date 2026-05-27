# 2879. Display the First Three Rows
# Difficulty: Easy
# https://leetcode.com/problems/display-the-first-three-rows/
# Runtime: 329 ms (beats —)
# Memory: 66.7 MB (beats —)
# Submitted: 2026-05-27

import pandas as pd

def selectFirstRows(employees: pd.DataFrame) -> pd.DataFrame:
    return employees.head(3)
    
