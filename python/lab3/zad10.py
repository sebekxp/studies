def numvowel(s):
    sum1 = 0
    for i in s:
        if i in "AaąEeęYyIiOoUuóÓ":
            sum1 += 1
    return sum1


def vowel(l):
    return [i for i in l if numvowel(i) % 2 == 0]


print(vowel(["Robot", "Mech", "Metal Gear", "Android"]))
