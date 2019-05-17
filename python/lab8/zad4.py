import random


def jednoreki_bandyta(coins):
    allowed = [1, 2, 5, 10, 20, 50]
    while coins:
        random_coins = random.choice(allowed)
        if (coins - random_coins) >= 0:
            yield random_coins
            coins -= random_coins


for i in jednoreki_bandyta(10):
    print(i)
