# coding=utf-8
import telebot
import constant
import random
from bs4 import BeautifulSoup
import re
from urllib.request import urlopen

import telegram
from time import sleep
#
import logging
import requests, json
import urllib.request, urllib.parse,urllib
import urllib.request
import re, sys, os, platform
import random  as  random_number
bot = telebot.TeleBot(constant.token)
# noinspection PyGlobalUndefined
global h, kj, ml


def news():

    URL = "https://www.yandex.ru"
    H = urlopen(URL)
    list25 = H.read().decode('utf-8')
    list1 = str(BeautifulSoup(list25))
    result = (re.findall(r'<li class="list__item"><a aria-label=\".*?\"', list1))

    result1 = re.sub(r'<li class="list__item"><a aria-label=', "", str(result))
    return str(result1)


def money(n):
    URL = "http://www.cbr.ru"
    H = urlopen(URL)
    listm = H.read().decode('utf-8')
    listm1 = str(BeautifulSoup(listm))
    resultm = (re.findall(r'<ins class="rubl">.*</div>', listm1))
    resultm1 = re.sub(r'<ins class="rubl">руб.</ins>', "", str(resultm))
    resultm1 = re.sub(r'xa0<i class="up" title="', "", str(resultm1))
    resultm1 = re.sub(r'xa0<i class="down" title="', "", str(resultm1))
    resultm1 = re.sub(r'</div>', "", str(resultm1))
    resultm1 = re.sub(r'</i>', "", str(resultm1))
    resultm1 = re.sub(r'\+ .*\">↑', "", str(resultm1))
    resultm1 = re.sub(r'- .*\">↓', "", str(resultm1))
    resultm1 = re.sub(r'\\', "", str(resultm1))
    resultm1 = resultm1.split()
    if n == 0:
        resultm2 = str(resultm1[n])[2:9]
    else:
        resultm2 = str(resultm1[n])[1:8]
    return resultm2


def ber(msg):
        ss = requests.Session()
        r = ss.get('https://yandex.ua/images/search?text=' + msg)
        p = 'div.class\=\"serp-item.*?url\"\:\"(.*?)\"'
        response = r.text
        w = re.findall(p, response)
        w = w[0:29:1]
        choice_f = random_number.choice(w)
        return choice_f
def you(hy):
    link = urllib.parse.urlencode({"search_query":hy})
    content = urllib.request.urlopen("https://www.youtube.com/results?" + link)
    search_results = re.findall('href=\"\/watch\?v=(.*?)\"',content.read().decode())
    search_results = search_results[0:9:1]
    choice_f = random_number.choice(search_results)
    yt_link = "https://www.youtube.com/watch?v=" + choice_f
    return yt_link

@bot.message_handler(commands=['start'])
def hanlde_start(message):
    user_markup = telebot.types.ReplyKeyboardMarkup(True, False)
    user_markup.row('/start', '/stop')
    user_markup.row('Повеселиться', 'Узнать новости', 'Курс валют')
    user_markup.row('Смотреть видео', 'Смотреть картинки', 'Закончить просмотр')
    kj = 0
    ml = 0
    bot.send_message(str(message.from_user.id), "{0} \n"
                                                ' чем бы ты хотел заняться ?  '.format(constant.hi),
                     reply_markup=user_markup)


@bot.message_handler(commands=['menu'])
def hanlde_menu(message):
    user_markup = telebot.types.ReplyKeyboardMarkup(True, False)
    user_markup.row('/start', '/stop')
    user_markup.row('Повеселиться', 'Смотреть картинки', 'Курс валют')
    user_markup.row('Смотреть видео', 'Смотреть картинки', 'Закончить просмотр')
    bot.send_message(str(message.from_user.id),
                     ' чем бы ты хотел заняться ?  ',
                     reply_markup=user_markup)


@bot.message_handler(commands=['startplay'])
def hanlde_menu(message):
    user_markup1 = telebot.types.ReplyKeyboardMarkup(True, False)
    user_markup1.row('/startplay', 'Начать', '/stopplay')
    user_markup1.row('Вытащить 1', 'Вытащить 2', 'Вытащить 3')
    bot.send_message(str(message.from_user.id),
                     ' Введите:"Начать"  ', reply_markup=user_markup1)


@bot.message_handler(commands=['stopplay'])
def hanlde_stop(message):
    hide_markup = telebot.types.ReplyKeyboardRemove()
    bot.send_message(str(message.from_user.id), 'Игра закончена',
                     reply_markup=hide_markup)


@bot.message_handler(commands=['stop'])
def hanlde_stop(message):
    hide_markup = telebot.types.ReplyKeyboardRemove()
    bot.send_message(str(message.from_user.id), 'Меню закрыто,для его возвращения введите коменду /menu',
                     reply_markup=hide_markup)


# noinspection PyGlobalUndefined
@bot.message_handler(content_types=['text'])
def hanlde_text(message):
    global kj, ml

    if message.text == "Привет" or message.text == "привет" or message.text == "прив":
        bot.send_message(str(message.from_user.id), "{0} \n"
                                                    ' чем бы ты хотел заняться ?  '.format(
            random.choice(constant.hello)))
        kj = 0
        ml = 0
    elif message.text == "/start":
        kj = 0
        ml = 0
    elif message.text == "Узнать новости" or message.text == "узнать новости":
        bot.send_message(str(message.from_user.id), news())
        bot.send_photo(str(message.from_user.id), ber("новости"))
        kj = 0
        ml = 0
    elif message.text == "Закончить просмотр":
        kj = 0
        ml = 0
    elif message.text == "Смотреть картинки":
        kj = 1
        ml = 0
        bot.send_message(str(message.from_user.id), "Что ты хочешь посмотреть?")

    elif message.text == "Смотреть видео":
        ml = 1
        kj = 0
        bot.send_message(str(message.from_user.id), "Что ты хочешь посмотреть?")
    elif message.text == "Курс валют" or message.text == "курс валют":
        kj = 0
        ml = 0
        bot.send_message(str(message.from_user.id), "Информация от ЦБ РФ\n" +
                                                    "Доллар США" + ":" + money(0) + 'руб' + "\n" +
                                                    "Евро" + ":" + money(1) + 'руб')

    elif message.text == "Повеселиться" or message.text == "повеселиться":
        kj = 0
        ml = 0
        bot.send_message(str(message.from_user.id), "Анекдот:\n" + random.choice(constant.hap))
        bot.send_photo(str(message.from_user.id),ber("Повеселиться"))

    elif kj == 1:
        bot.send_photo(str(message.from_user.id), ber(message.text))
    elif ml == 1:
        bot.send_message(str(message.from_user.id), text=you(message.text))

    elif message.text == 'Вытащить 1' or message.text == 'Вытащить 2' or message.text == 'Вытащить 3'\
            or message.text == 'Начать' \
            or message.text == "начать" or message.text == "/stopplay" or message.text == "/startplay":
        global l, l1, h

        if message.text == "/stopplay":
            h = 0
        elif message.text == "/startplay" or message.text == "Начать" or message.text == "начать":
            bot.send_message(str(message.from_user.id), "Я умею играть в игру спички.Правила очень простые.Выпадает "
                                                        "рандомное число \n "
                                                        "спичек.Мы поочереди тянем спички,от 1 до 3.Проиграет тот ,"
                                                        "кто вытащит последнюю\n  ")

            l = random.choice(range(9, 55))
            h = 1
            bot.send_message(str(message.from_user.id),
                             "Автоматически выпало число: " + str(l) + "\nесли выпадит 1,то ходишь ты,если 0,то я  ")

            if (l - 1) % 4 == 3:
                l1 = str(int(l) - 3)
                bot.send_message(str(message.from_user.id), "Автоматически выпало число :" + " 0\n" +
                                 "Я хожу.Из {0} я отнимаю 3 . Осталость {1}.Твой ход".format(l, l1))
            if (l - 1) % 4 == 2:
                l1 = str(int(l) - 2)
                bot.send_message(str(message.from_user.id), "Автоматически выпало число :" + "0\n" +
                                 "Я хожу.Из {0} я отнимаю 2 . Осталость {1}.Твой ход".format(l, l1))
            if (l - 1) % 4 == 1:
                l1 = str(int(l) - 1)
                bot.send_message(str(message.from_user.id), "Автоматически выпало число :" + "0\n" +
                                 "Я хожу.Из {0} я отнимаю 1 . Осталость {1}.Твой ход".format(l, l1))
            if (l - 1) % 4 == 0:
                bot.send_message(str(message.from_user.id), "Автоматически выпало число :" + "1\n" +
                                 "Ты ходишь.")

            l1 = l
            h = 1
        elif h == 1 and (message.text == 'Вытащить 1' or message.text == 'Вытащить 2' or message.text == 'Вытащить 3'):
            if message.text == 'Вытащить 1':
                l1 = str(int(l) - 1)
                bot.send_message(str(message.from_user.id), "Ты из {0} вычел 1 , осталость {1}".format(l, l1))
                if int(l1) == 4:
                    l = str(int(l1) - 3)
                    bot.send_message(str(message.from_user.id), 'Я хожу \n'
                                                                'Из 4 я отнимаю 3 . Осталость 1.Ты проиграл.\n'
                                                                'Игра закончена'.format(l1, l))
                    h = 0
                elif int(l1) == 3:
                    l = str(int(l1) - 2)
                    bot.send_message(str(message.from_user.id), 'Я хожу \n'
                                                                'Из 3 я отнимаю 2 . Осталость 1.Ты проиграл.\n'
                                                                'Игра закончена'.format(l1, l))
                    h = 0
                elif int(l1) == 2:
                    l = str(int(l1) - 1)
                    bot.send_message(str(message.from_user.id), 'Я хожу \n'
                                                                'Из 2 я отнимаю 1 . Осталость 1.Ты проиграл.\n'
                                                                'Игра закончена'.format(l1, l))
                    h = 0
                else:
                    l = str(int(l1) - 3)
                    bot.send_message(str(message.from_user.id), 'Я хожу \n'
                                                                'Из {0} я отнимаю 3 . Осталость {1}.Ты ходишь.\n'
                                                                .format(l1, l))

            elif message.text == 'Вытащить 2':
                l1 = str(int(l) - 2)
                bot.send_message(str(message.from_user.id), "Ты из {0} вычел 2 , осталость {1}".format(l, l1))

                if int(l1) == 4:
                    l = str(int(l1) - 3)
                    bot.send_message(str(message.from_user.id), 'Я хожу \n'
                                                                'Из 4 я отнимаю 3 . Осталость 1.Ты проиграл.\n'
                                                                'Игра закончена'.format(l1, l))
                    h = 0
                elif int(l1) == 3:
                    l = str(int(l1) - 2)
                    bot.send_message(str(message.from_user.id), 'Я хожу \n'
                                                                'Из 3 я отнимаю 2 . Осталость 1.Ты проиграл.\n'
                                                                'Игра закончена'.format(l1, l))
                    h = 0
                elif int(l1) == 2:
                    l = str(int(l1) - 1)
                    bot.send_message(str(message.from_user.id), 'Я хожу \n'
                                                                'Из 2 я отнимаю 1 . Осталость 1.Ты проиграл.\n'
                                                                'Игра закончена'.format(l1, l))
                    h = 0
                else:
                    l = str(int(l1) - 2)
                    bot.send_message(str(message.from_user.id), 'Я хожу \n'
                                                                '.Из {0} я отнимаю 2 . Осталость {1}.Ты ходишь.\n'
                                                                .format(l1, l))
            elif message.text == 'Вытащить 3':
                l1 = str(int(l) - 3)
                bot.send_message(str(message.from_user.id), "Ты из {0} вычел 3 , осталость {1}".format(l, l1))
                if int(l1) == 4:
                    l = str(int(l1) - 3)
                    bot.send_message(str(message.from_user.id), 'Я хожу \n'
                                                                'Из 4 я отнимаю 3 . Осталость 1.Ты проиграл.\n'
                                                                'Игра закончена'.format(l1, l))
                    h = 0
                elif int(l1) == 3:
                    l = str(int(l1) - 2)
                    bot.send_message(str(message.from_user.id), 'Я хожу \n'
                                                                'Из 3 я отнимаю 2 . Осталость 1.Ты проиграл.\n'
                                                                'Игра закончена'.format(l1, l))
                    h = 0
                elif int(l1) == 2:
                    l = str(int(l1) - 1)
                    bot.send_message(str(message.from_user.id), 'Я хожу \n'
                                                                'Из 2 я отнимаю 1 . Осталость 1.Ты проиграл.\n'
                                                                'Игра закончена'.format(l1, l))
                    h = 0
                else:
                    l = str(int(l1) - 1)
                    bot.send_message(str(message.from_user.id), 'Я хожу \n'
                                                                '.Из {0} я отнимаю 1 . Осталость {1}.Ты ходишь.\n'
                                                                .format(l1, l))
        else:
            bot.send_message(str(message.from_user.id),
                             "К сожалению ,игра закончилась.Введите 'Поиграть' ,чтобы начать заново ")

    else:
        bot.send_message(str(message.from_user.id), "К сожалению , я пока не могу понять все то , что ты мне говоришь")
    print("{0} от {1} ".format(message.text, message.from_user.first_name))


bot.polling(none_stop=True, interval=0)
