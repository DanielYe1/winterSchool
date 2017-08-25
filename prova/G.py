x = input()

l = []

l.append(x.count('n')/3)
l.append(x.count('e')/3)
l.append(x.count('t'))
l.append(x.count('i'))



print(int(sorted(l)[0]))