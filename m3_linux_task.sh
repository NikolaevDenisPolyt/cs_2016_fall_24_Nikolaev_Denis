 wget yandex.ru;cat index.html|grep -o -E 'yes" aria-label="[^"]+"' >text1;cat text1|sed -e 's/yes" aria-label=//g' >text2;cat text2|sed -e 's/"Котировки"/Погода/g' >text1;rm index.html;rm text2;

