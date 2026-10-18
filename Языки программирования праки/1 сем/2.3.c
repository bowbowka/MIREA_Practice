#include <stdio.h>
#include <string.h>

void create_user(); // Даем возможность ТОЛЬКО АДМИНУ создать пользователя
int log_in();
int file_exists(const char* filename);

int main() {
    printf("What would you like to do?\n 1. Log in\n 2. Create a new user\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        int is_logined = 0;
        while (is_logined == 0) {
            printf("Please, log in\n\n");
            is_logined = log_in();
        }
    }
    else if (choice == 2) {
        create_user();
    }
    else {
        printf("Enter a correct number. \n");
    }
}

int log_in() {
    printf("Enter a username:\n");
    char u_buf[20]; // Юзернейм
    scanf("%19s", u_buf);
    FILE* user = fopen(u_buf, "r");
    if (user == NULL) {
        printf("No such user");
        printf("\n");
        return 0; // не даем выйти из основного цикла логина
    }
    printf("Enter a password:\n");
    char p_buf[20]; // Пароль
    scanf("%19s", p_buf);

    char fu_buf[20], fp_buf[20]; // буферы прочтенных логина и пароля и файла file user buf / file pass buf
    if (fscanf(user, "%19s %19s", fu_buf, fp_buf) != 2) {
        printf("Reading error\n");
        fclose(user);
        return 0;
    }

    fclose(user);

    // Проверяем пароль
    p_buf[19] = '\0';
    fp_buf[19] = '\0';
    if (strcmp(p_buf, fp_buf) == 0) {
        printf("Successfully logined!\n");
        return 1;
    }
    else {
        printf("Wrong password\n");
        return 0;
    }
}

int file_exists(const char* filename){
    FILE* f = fopen(filename, "r");
    if (f != NULL) {
        fclose(f);
        return 1;
    }
    return 0;
}

void create_user() {
    printf("Please, enter the SUPER ADMIN PASSWORD. \n"); // SAP: pasha123
    char pass[20];
    scanf("%19s", pass);
    pass[19] = '\0';
    if (strcmp(pass, "pasha123") != 0) {
        printf("Wrong admin password, you can not create a user.\n");
        return;
    }
    char new_user[20];
    printf("Enter new user's username: \n");
    scanf("%19s", new_user);
    if (file_exists(new_user) == 1) {
        printf("File already exists. Would you like to rewrite it?\n[y/n]\n");
        char yn;
        scanf(" %c", &yn);
        if (yn == 'n' || yn == 'N') return;
    }
    FILE* user = fopen(new_user, "w");
    if (user == NULL) {
            printf("Ошибка открытия файла!\n");
            return;
        }
    printf("Please, enter new user's password.\n");
    scanf("%19s", pass);
    pass[19] = '\0';
    fprintf(user, "%s %s", new_user, pass);
    fclose(user);
    printf("Created a new user: %s:%s", new_user, pass);
}
