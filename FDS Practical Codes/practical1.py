# a) List of students who play both cricket and badminton
# b) List of students who play either cricket or badminton but not both
# c) Number of students who play neither cricket nor badminton
# d) Number of students who play cricket and football but not badminton.

def searchSet(lst, elem):
    for i in range(len(lst)):  # lst = 2 4 6 8 10
        if lst[i] == elem:
            return True
    return False

def findUnionSet(A, B):
    C = A[:]
    for i in range(len(B)):
        if searchSet(C, B[i]) != True:
            C.append(B[i])
    return C

def findIntersectionSet(A,B):
    C = []
    for i in range (len(A)):
        if searchSet(B, A[i]) == True:
            C.append(A[i])
    return C

def findDifferenceSet(A, B):  
    C=[]
    for i in range(len(A)):
        if searchSet(B,A[i]) != True:
            C.append(A[i])
    return C

# def remove_duplicate(lst):
#     C=[]
#     for i in range(len(lst)):
#         if searchSet(C, lst[i]) != True:
#             C.append(lst[i])
#     return C

n = int(input("Enter total number of students in the class: "))

print("Enter the names of students who play cricket: ")
cricket = input().split()
print("Enter the names of students who play badminton: ")
badminton = input().split()
print("Enter the names of students who play football: ")
football = input().split()

allStudents = findUnionSet(findUnionSet(cricket,badminton),football)

#List of students who play both cricket and badminton
BothCricketAndBadminton = findIntersectionSet(cricket, badminton)

#List of students who play either cricket or badminton but not both
EitherCricketOrBadminton = findUnionSet(cricket, badminton)
EitherCricketOrBadmintonNotBoth = findDifferenceSet(EitherCricketOrBadminton, BothCricketAndBadminton)

#Number of students who play neither cricket nor badminton
neitherCricketNorBadminton = findDifferenceSet(allStudents,EitherCricketOrBadminton)

#Number of students who play cricket and football but not badminton.
BothCricketAndFootball = findIntersectionSet(cricket, football)
BothCricketAndFootballNotBadminton = findDifferenceSet(BothCricketAndFootball, badminton)

print("a) Students who play both cricket and badminton: ", BothCricketAndBadminton)
print("b) Students who play either cricket or badminton but not both:", EitherCricketOrBadmintonNotBoth)
print("c) Number of students who play neither cricket nor badminton:", len(neitherCricketNorBadminton))
print("d) Number of students who play cricket and football but not badminton:", len(BothCricketAndFootballNotBadminton))