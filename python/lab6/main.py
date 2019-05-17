from numpy import random
from tkinter import *
from tkinter import ttk
import csv
import datetime


class BadCoinException(Exception):
    def __init__(self, message):
        self._message = message

    def get_message(self):
        return self._message


class UnknownCurrencyException(Exception):
    def __init__(self, message):
        self._message = message

    def get_message(self):
        return self._message


class ListOfCoinsException:
    _list_of_monet = []

    def add(self, coin):
        self._list_of_monet.append(coin.get_coin())

    def get_list_of_money(self):
        return self._list_of_monet


class BadFileFormatException(Exception, ListOfCoinsException):
    def __init__(self, message):
        self._message = message

    def get_message(self):
        return self._message


class HeHitTheFingerException(Exception):
    def __init__(self, message):
        self._message = message

    def get_message(self):
        return self._message


class Coins:
    def __init__(self, tmp_coin, tmp_currency):
        allowed_coins = [0.01, 0.02, 0.05, 0.1, 0.2, 0.5, 1, 2, 5]
        allowed_currency = ["PLN", "EUR", "GP"]
        try:
            if tmp_coin not in allowed_coins:
                raise BadCoinException("Not allowed coin")
            if tmp_currency not in allowed_currency:
                raise UnknownCurrencyException("Not allowed currency")

        except BadCoinException as e:
            print(e.get_message())
        except UnknownCurrencyException as u:
            print(u.get_message())

        self._coin = tmp_coin
        self._currency = tmp_currency
        self.identified = False
        self.numismatic_value = None

    def get_coin(self):
        return self._coin

    def get_currency(self):
        return self._currency

    # def __str__(self):
    #     return f"Description XDD, Currency: {self.get_currency()}, Coin: {self.get_coin()}"
    #
    # def __repr__(self):
    #     return f"Tekst opisujacy monete: {self.get_coin()} "


class CoinStorage:
    _coin_storage = []
    _sum = 0

    def __init__(self, allowed_coins):
        self._allowed_coins = allowed_coins

    def add_coins(self, m):
        self._coin_storage.append(m)
        assert m.get_coin() in self._allowed_coins, "Not allowed coin"
        self._sum += m.get_coin()

    def get_sum_of_money(self):
        return self._sum

    def take_coin_of_given_denomination(self, searched_value):
        self._sum -= searched_value.get_coin()
        return self._coin_storage.remove(searched_value)


class Piggybank(CoinStorage):
    _piggybank = []
    _supported_currency = "PLN"

    def __init__(self, allowed_coins):
        super().__init__(allowed_coins)
        self._broken = False

    def add_to_piggybank(self, coin):
        if not self._broken:
            try:
                if coin.get_coin() not in self._allowed_coins:
                    raise BadCoinException("Not allowed coin")
                if coin.get_currency() not in self._supported_currency:
                    raise UnknownCurrencyException("Not allowed currency")
            except BadCoinException as c:
                print(c.get_message())
            except UnknownCurrencyException as u:
                print(u.get_message())
            assert (isinstance(coin, Coins)), 'The object being sent is not a coin'
            # assert coin.get_coin() in self._allowed_coins, "Not allowed coin"
            # assert coin.get_currency() in self._supported_currency, "Unknown currency"
            self._piggybank.append(coin)
        else:
            print("You can not add money to broken piggybank")

    def get_sum(self):
        sum = 0
        for i in self._piggybank:
            sum += i.get_coin()
        return sum

    def get_piggybank(self):
        return self._piggybank

    def take_coin_of_given_denomination(self, searched_value):
        print("Can not be pulled out single coin ")

    def broke(self):
        rnd = random.randint(1, 10)
        try:
            if rnd == 1:
                with open("pamietnik.txt", 'a') as p:
                    p.write(f"{datetime.datetime.now()}, Drogi pamiętniczku, mój palec znowu napotkał młotek na swej drodze. Bolało.\n")
                raise HeHitTheFingerException("You hit the finger XD")
            else:
                self._broken = True

                return [self._piggybank.pop() for i in range(len(self._piggybank))]

        except HeHitTheFingerException as h:
            print(h.get_message())


class Goldpiggybank(Piggybank, Coins):
    def __init__(self, allowed_coins, tmp_coin, tmp_currency):
        Piggybank.__init__(self, allowed_coins)
        Coins.__init__(self, tmp_coin, tmp_currency)
        self._value_of_goldpiggybank = 9000


class Numismatist:
    _value0_coins = []
    _value1000_coins = []
    _value2000_coins = []

    def identify(self, coin):
        coin.identified = True
        random_year = random.triangular(1900, 2017, 2019)
        if random_year <= 1939:
            coin.numismatic_value = 1000
            self._value1000_coins.append(coin.get_coin())
        elif random_year <= 1914:
            coin.numismatic_value = 2000
            self._value2000_coins.append(coin.get_coin())
        else:
            coin.numismatic_value = 0
            self._value0_coins.append(coin.get_coin())

        hasattr(coin, "Coins")

    def sell(self, coin):
        if not coin.identified:
            self.identify(coin)
        if coin.numismatic_value == 0:
            return coin.get_coin()
        elif coin.numismatic_value == 1000:
            return self._value1000_coins
        else:
            return self._value2000_coins

    def transmute(self, coin):
        coin.identified = False
        del coin.numismatic_value


piggybank = Piggybank([0.1, 0.2, 0.5, 2, 0.01, 0.02, 0.05, 5])

coin_storage = CoinStorage([0.1, 0.2, 0.5, 2, 0.01, 0.02, 0.05, 5])


# coin1 = Coins(0.1, "PLN")
# coin2 = Coins(0.2, "PLN")
# coin3 = Coins(0.5, "EUR")
# coin4 = Coins(5, "PLN")
#
# coin5 = Coins(4.5, "PLN")
# coin6 = Coins(5, "PL")

# print(str(Coins(2, "PLN")))
# print(repr(Coins(2, "PLN")))

# piggybank.add_to_piggybank(coin1)
# piggybank.add_to_piggybank(coin2)
# # piggybank.add_to_piggybank(coin3)
# # piggybank.add_to_piggybank(coin4)
# print(piggybank.get_sum_of_money())
# piggybank.take_coin_of_given_denomination(coin1)
#
# coin_storage.add_coins(coin1)
# coin_storage.add_coins(coin2)
# coin_storage.add_coins(coin3)
# # coin_storage.add_coins(coin4)
# print(coin_storage.get_sum_of_money())
# coin_storage.take_coin_of_given_denomination(coin1)
# print(coin_storage.get_sum_of_money())
#
# print(issubclass(Piggybank, CoinStorage))
# print(issubclass(int, CoinStorage))
#
# gold = Goldpiggybank([0.1, 0.2, 0.5], 0.1, "PLN")

# numismatist = Numismatist()
# numismatist.identify(coin1)
# numismatist.identify(coin2)
# numismatist.identify(coin3)
# numismatist.identify(coin4)
# print(numismatist.sell(coin1))
# print(numismatist.sell(coin2))
# print(numismatist.sell(coin3))
# print(numismatist.sell(coin4))
#
# COINS = [Coins(0.1, "PLN"),
#          Coins(0.5, "PLN"),
#          Coins(0.2, "PLN"),
#          Coins(2, "PLN")]
# window = Tk()
# window.title("Piggybank")
# mainframe = ttk.Frame(window)
# mainframe.grid(column=0, row=0, sticky=(N, W, E, S))
# i = 0
# for c in COINS:
#     ttk.Button(mainframe, text="Wrzuć " + str(c.get_coin()) + "zł",
#                command=lambda c=c: piggybank.add_to_piggybank(c)).grid(column=2, row=i)
#     i += 1
#     ttk.Button(mainframe, text="Cash",
#                command=lambda: print(piggybank.get_sum())).grid(column=1, row=0)
# window.mainloop()
#
def load_from_file():
    l = ListOfCoinsException()
    file = 'dane.csv'
    try:
        with open(file, 'r') as csvFile:
            reader = csv.reader(csvFile)
            for row in reader:
                if len(row) != 2:
                    raise BadFileFormatException("Bad file format")
                amount = row[1]
                amount = int(amount)
                while amount:
                    row[0] = float(row[0])
                    tmp_coin = Coins(row[0], "PLN")
                    piggybank.add_to_piggybank(tmp_coin)
                    amount -= 1
        csvFile.close()
    except BadFileFormatException as b:
        print(b.get_message())



# print(piggybank.get_sum())
load_from_file()
# print(piggybank.get_sum())
money_from_pig = piggybank.broke()
piggybank.broke()
piggybank.broke()
piggybank.broke()
piggybank.broke()
# print(piggybank.get_sum())

# for i in money_from_pig:
#     print(i.get_coin())
