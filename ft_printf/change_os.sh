if grep -q '<stdio.h>' libftprintf.h
then sed -i '' 's/<stdio.h>/<io.h>/' libftprintf.h; echo "\033[0;31mReady to compile on Windows!\033[0m"
else
sed -i '' 's/<io.h>/<stdio.h>/' libftprintf.h; echo "\033[0;31mReady to compile on Unix!\033[0m"
fi