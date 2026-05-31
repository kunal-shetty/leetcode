# 2884. Modify Columns
# Difficulty: Easy
# https://leetcode.com/problems/modify-columns/
# Runtime: 243 ms (beats —)
# Memory: 66.5 MB (beats —)
# Submitted: 2026-05-31

import pandas as pd

def modifySalaryColumn(employees: pd.DataFrame) -> pd.DataFrame:
    employees['salary'] = employees['salary'] * 2
    return employees
