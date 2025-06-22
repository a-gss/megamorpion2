void editText(char *buf, int len, int y, int x)
{
    unsigned int charCount = 0;
    unsigned int pos = 0;
    ch = 0;

    memset(buf, ' ', len);

    while((ch != KEY_ENTER) || (charCount == 0)) {
        switch (ch) {
            default: // inser mode
                if (isprint(ch)) buf[pos] = ch;

                // prevent charCount from increasing if we modify a letter in the middle
                if (pos == charCount) charCount++;
                pos++;
                break;

            case KEY_BACKSPACE:
                if (charCount > 0) {
                    charCount--;
                    pos--;
                    buf[pos] = ' ';
                } break;

            case KEY_LEFT:  if(pos > 0) {pos--;} break;
            case KEY_RIGHT: if(pos < charCount) {pos++;} break;
            case KEY_UP:    break;
            case KEY_DOWN:  break;
            case KEY_ENTER: break;
            case TERM_RESIZE: break;
            case 0: break;
        }

        // Draw
        for (int i = 0; i <= charCount; i++) {
            mvprintw(y, x+i, "%c ", buf[i]);
        }
        if (pos == charCount) {
            attron(A_BLINK);
            mvprintw(y, x+pos, "_");
            attroff(A_BLINK);
        } else {
            attron(A_REVERSE | A_BOLD);
            mvprintw(y, x+pos, "%c", buf[pos]);
            attroff(A_REVERSE | A_BOLD);
        }

        getCH();
    }

    // Erase cursor
    mvprintw(y, x+pos, "%c", buf[pos]);
    mvprintw(y, x+charCount, " ");

    buf[charCount] = '\0';
}
