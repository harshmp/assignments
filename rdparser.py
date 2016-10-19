# The grammar accpeted by this parser:      E  -> iEd
#                                           Ed -> +iEd | $

p = 0
flag = True

def E():
    global p
    if string[p]=='i':
        match('i')
        Ed()

def Ed():
    global p
    if string[p]=='+':
        match('+')
        match('i')
        Ed()
    else:
        return

def match(t):
    global p
    global flag
    if string[p]==t:
        p+=1
    else:
        flag = False

string = raw_input("Enter the string: ")
E()
if (string[p]=='$' and flag):
    print "Accepted!"
else:
    print "Rejected!"
