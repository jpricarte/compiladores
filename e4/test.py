import emoji
from os import listdir
import subprocess as sp
from os.path import isfile, join
from sys import argv

ETAPA = 4

def verifica_etapa4():
    def readable_code(code: int) -> str:
        if code == 10:
            return 'ERR_UNDECLARED'
        if code == 11:
            return 'ERR_DECLARED'
        if code == 20:
            return 'ERR_VARIABLE'
        if code == 21:
            return 'ERR_ARRAY'
        if code == 22:
            return 'ERR_FUNCTION'
        if code == 31:
            return 'ERR_CHAR_TO_INT'
        if code == 32:
            return 'ERR_CHAR_TO_FLOAT'
        if code == 33:
            return 'ERR_CHAR_TO_BOOL'
        if code == 34:
            return 'ERR_CHAR_VECTOR'
        if code == 35:
            return 'ERR_X_TO_CHAR'
        else:
            return 'ERR_ON_PARSER_OR_LEXER'

    # error-msgs
    valid_tests_path = argv[1]
    valid_tests = [f for f in listdir(valid_tests_path) if isfile(join(valid_tests_path, f))]

    for test in valid_tests:
        try:
            sp.check_output(f'./etapa{ETAPA} < {valid_tests_path}/{test}', shell=True)
            print(emoji.emojize(f':check_mark: teste {test}'))
        except sp.CalledProcessError as e:
            print(emoji.emojize(f':warning: teste {test}, código retornado: {readable_code(e.returncode)}'))


if __name__ == "__main__":
    verifica_etapa4()