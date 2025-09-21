#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ncurses.h>

#define MAX        100
#define ARRAYMAX   5
#define MAX_HEIGHT 10  // Maximum height of vertical bars in lines

void makegraph(float p[]);
void draw_border(int starty, int startx, int height, int width);

int main(void)
{
    int i;
    int scores[ARRAYMAX];
    float percents[ARRAYMAX];

    // Initialize ncurses
    initscr();
    cbreak();
    noecho();

    // Check if terminal supports color
    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_BLACK, COLOR_BLUE);   // For bars
        init_pair(2, COLOR_GREEN, COLOR_BLACK);  // For percentage labels
    }

    // Welcome screen
    clear();
    draw_border(2, 2, 12, 35);
    attron(COLOR_PAIR(1));
    mvprintw(4, 4, "Welcome to Bar Graph Program");
    attroff(COLOR_PAIR(1));
    mvprintw(8, 4, "Press Enter to continue.");
    refresh();
    getch();  // Pause for Enter
    clear();

    // Input scores
    for (i = 0; i < ARRAYMAX; i++) {
        mvprintw(2, 2, "Enter score %d (0-%d): ", i + 1, MAX);
        refresh();
        int score;
        if (scanw("%d", &score) != 1 || score < 0 || score > MAX) {
            mvprintw(4, 2, "Invalid input. Setting to 0.");
            refresh();
            scores[i] = 0;
            getch();
            clear();
        } else {
            scores[i] = score;
            clear();
        }
    }

    // Calculate percentages
    for (i = 0; i < ARRAYMAX; i++) {
        percents[i] = ((float) scores[i]) / MAX;
    }

    // Display scores and percentages
    clear();
    mvprintw(2, 2, "Statistical Data:");
    for (i = 0; i < ARRAYMAX; i++) {
        attron(COLOR_PAIR(2));
        mvprintw(4 + i, 2, "%d. \t%d\t%3.0f%%", i + 1, scores[i], (percents[i] * 100));
        attroff(COLOR_PAIR(2));
    }
    mvprintw(4 + ARRAYMAX + 2, 2, "Press Enter to continue...");
    refresh();
    getch();  // Pause
    clear();

    makegraph(percents);

    // Clean up and exit
    endwin();
    return 0;
}

void makegraph(float p[])
{
    int i, j;
    int heights[ARRAYMAX];
    int max_height = MAX_HEIGHT;  // Maximum lines for the tallest bar

    // Calculate bar heights based on percentages
    for (i = 0; i < ARRAYMAX; i++) {
        heights[i] = (int)(p[i] * max_height);  // Scale to max_height
        if (heights[i] > max_height) heights[i] = max_height;  // Cap at max_height
    }

    // Print vertical graph
    mvprintw(2, 2, "Vertical ASCII Bar Graph (Percentages):");
    mvprintw(3, 2, "Each '*' represents approximately %.1f%%.", (100.0 / max_height));
    refresh();

    // Print vertical graph from top to bottom
    for (j = max_height; j >= 0; j--) {
        // Print percentage label on Y-axis
        if (j % 1 == 0) {
            attron(COLOR_PAIR(2));
            mvprintw(5 + (max_height - j), 2, "%3d  |", j);
            attroff(COLOR_PAIR(2));
        } else {
            mvprintw(5 + (max_height - j), 2, "      |");
        }

        // Print bars
        for (i = 0; i < ARRAYMAX; i++) {
            if (heights[i] >= j && j > 0) {
                attron(COLOR_PAIR(1));
                mvprintw(5 + (max_height - j), 8 + i * 4, "   ");
                attroff(COLOR_PAIR(1));
            } else if (j == 0) {
                mvprintw(5 + (max_height - j), 8 + i * 4, "----");  // X-axis base
            } else {
                mvprintw(5 + (max_height - j), 8 + i * 4, "    ");
            }
        }
    }

    // Print X-axis labels (bar indices)
    mvprintw(5 + max_height + 1, 8, "");
    for (i = 0; i < ARRAYMAX; i++) {
        mvprintw(5 + max_height + 1, 8 + i * 4, "%3d ", i + 1);
    }
    mvprintw(5 + max_height + 2, 8, "Poverty & Education");

    mvprintw(5 + max_height + 4, 2, "Press Enter to exit...");
    refresh();
    getch();
}

void draw_border(int starty, int startx, int height, int width)
{
    // Draw top and bottom borders
    for (int i = 0; i < width; i++) {
        mvprintw(starty, startx + i, "-");
        mvprintw(starty + height - 1, startx + i, "-");
    }
    // Draw side borders
    for (int i = 0; i < height; i++) {
        mvprintw(starty + i, startx, "|");
        mvprintw(starty + i, startx + width - 1, "|");
    }
    // Draw corners
    mvprintw(starty, startx, "+");
    mvprintw(starty, startx + width - 1, "+");
    mvprintw(starty + height - 1, startx, "+");
    mvprintw(starty + height - 1, startx + width - 1, "+");
}
