# i have to create  -- testcases + grading criteria

from arithmatic1 import addNum,mulNum,subNum

def test_addNum():
    try:
        assert addNum(5,5) == 10
    except:
        raise AssertionError
    else:
        point = 2
        with open('output.txt','a') as file:
            file.write(str(point) + "\n")

def test_mulNum():
    try:
        assert mulNum(5,5) == 25
    except:
        print("error")
    else:
        point =5 
        with open('output.txt','a') as file:
            file.write(str(point)+ "\n")

def test_subNum():
    try:
        assert subNum(5,5) == 0
    except:
        raise AssertionError
    else:
        point = 3
        with open('output.txt','a') as file:
            file.write(str(point)+ "\n")