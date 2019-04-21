#include "mainMenu.h"

int closeMenu(int numberOfItems, MENU * menu, ITEM **items);

int mainMenu(int numberOfItems, char *choises[]) {
    MENU *menu;
    ITEM **items = malloc(sizeof(**items) * numberOfItems);

    int i, c;
    for (i = 0; i < numberOfItems; ++i) {
        items[i] = new_item(choises[i], "");
    }
    items[i] = (ITEM *) NULL;

    menu = new_menu(items);
    post_menu(menu);
    refresh();
    ITEM *chosen_item;
    int chosen_index;
    while (true) {
        c = getch();
        switch (c){
            case 's':
            case KEY_DOWN:
                menu_driver(menu, REQ_DOWN_ITEM);
                break;
            case 'w':
            case KEY_UP:
                menu_driver(menu, REQ_UP_ITEM);
                break;
            case '\n':
                chosen_item = current_item(menu);
                chosen_index = item_index(chosen_item);
                closeMenu(numberOfItems, menu, items);
                return chosen_index;
            default:
                break;

        }
    }
}


int closeMenu(int numberOfItems, MENU * menu, ITEM **items) {
    unpost_menu(menu);
    free_menu(menu);
    for (int i = 0; i < numberOfItems; ++i) {
        free_item(items[i]);
    }
    return 1;
}
