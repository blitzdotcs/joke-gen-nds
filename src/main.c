#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *jokes[] = {
    "Why did the tomato turn red?\nBecause it saw the salad dressing!",
    "Why did the scarecrow win an award?\nBecause he was outstanding in his field!",
    "Why did the cookie go to the doctor?\nBecause it was feeling crumbly!",
    "Why was the math book sad?\nBecause it had too many problems.",
    "Why did the bicycle fall over?\nBecause it was two-tired!",
    "Parallel lines have so much in common.\nIt's a shame they'll never meet.",
    "Why don't skeletons fight each other?\nThey don't have the guts.",
    "What did the grape say when it got stepped on?\nNothing, it just let out a little wine.",
    "I'm reading a book on anti-gravity.\nIt's impossible to put down.",
    "How do you organize a space party?\nYou 'planet'!",
    "I used to play piano by ear, but now I use my hands.",
    "I told my wife she was drawing her eyebrows too high.\nShe looked surprised.",
    "I'm on a whiskey diet.\nI've lost three days already.",
    "Why don't scientists trust atoms?\nBecause they make up everything.",
    "Did you hear about the claustrophobic astronaut?\nHe just needed a little space.",
    "I used to be a baker, but I couldn't make enough dough.",
    "What do you call a bear with no teeth?\nA gummy bear.",
    "I'm so good at sleeping that I can do it with my eyes closed.",
    "Why did the math book look sad?\nBecause it had too many problems.",
    "Why did the bicycle fall over?\nBecause it was two-tired!",
    "I used to be a baker, but I couldn't make enough dough.",
    "What did one wall say to the other wall?\n'I'll meet you at the corner!'",
    "What's orange and sounds like a parrot?\nA carrot.",
    "Why don't scientists trust atoms?\nBecause they make up everything.",
    "I couldn't figure out why the baseball kept getting larger.\nThen it hit me.",
    "I'm so good at sleeping that I can do it with my eyes closed.",
    "I used to be a baker, but I couldn't make enough dough.",
    "I don't trust stairs because they're always up to something.",
    "Why don't skeletons fight each other?\nThey don't have the guts.",
    "I used to play piano by ear, but now I use my hands.",
    "What do you call a fish with no eyes?\nFsh.",
    "I used to be a baker, but I couldn't make enough dough.",
    "I'm on a whiskey diet.\nI've lost three days already.",
    "I'm reading a book on anti-gravity.\nIt's impossible to put down.",
    "What's orange and sounds like a parrot?\nA carrot.",
    "I don't trust stairs because they're always up to something.",
    "I used to be a baker, but I couldn't make enough dough.",
    "I told my wife she was drawing her eyebrows too high.\nShe looked surprised.",
    "I'm on a whiskey diet.\nI've lost three days already.",
    "Why don't scientists trust atoms?\nBecause they make up everything.",
    "What do you call a bear with no teeth?\nA gummy bear.",
    "I'm so good at sleeping that I can do it with my eyes closed.",
    "I couldn't figure out why the baseball kept getting larger.\nThen it hit me.",
    "I'm so good at sleeping that I can do it with my eyes closed.",
    "I used to be a baker, but I couldn't make enough dough.",
    "I don't trust stairs because they're always up to something.",
    "Why don't skeletons fight each other?\nThey don't have the guts.",
    "I used to play piano by ear, but now I use my hands.",
    "What do you call a fish with no eyes?\nFsh.",
    "I used to be a baker, but I couldn't make enough dough.",
    "I'm on a whiskey diet.\nI've lost three days already.",
    "I'm reading a book on anti-gravity.\nIt's impossible to put down.",
    "What's orange and sounds like a parrot?\nA carrot.",
    "I don't trust stairs because they're always up to something.",
    "I used to be a baker, but I couldn't make enough dough.",
    "I told my wife she was drawing her eyebrows too high.\nShe looked surprised.",
    "I'm on a whiskey diet.\nI've lost three days already.",
    "Why don't scientists trust atoms?\nBecause they make up everything.",
    "What do you call a bear with no teeth?\nA gummy bear.",
    "I'm so good at sleeping that I can do it with my eyes closed.",
    "I couldn't figure out why the baseball kept getting larger.\nThen it hit me.",
    "Why did the chicken join a band?\nBecause it had the drumsticks.",
    "What do you call a belt made of watches?\nA waist of time.",
    "Why did the scarecrow win an award?\nBecause he was outstanding in his field.",
    "Why did the coffee file a police report?\nIt got mugged.",
    "How does a penguin build its house?\nIgloos it together.",
    "I used to be a baker, but I couldn't make enough dough.",
    "I'm on a whiskey diet.\nI've lost three days already.",
    "I'm reading a book on anti-gravity.\nIt's impossible to put down.",
    "What's orange and sounds like a parrot?\nA carrot.",
    "I don't trust stairs because they're always up to something."
};

void show_joke(int currentJokeIndex)
{
    iprintf("%s\n", jokes[currentJokeIndex]);
}

int main(void)
{
    videoSetMode(MODE_0_2D);
    videoSetModeSub(MODE_0_2D);

    vramSetBankA(VRAM_A_MAIN_BG);
    vramSetBankC(VRAM_C_SUB_BG);

    int mainBg = bgInit(3, BgType_Text4bpp, BgSize_T_256x256, 0, 0);
    int subBg = bgInitSub(3, BgType_Text4bpp, BgSize_T_256x256, 0, 0);

    consoleDemoInit();

    int currentJokeIndex = 0;
    show_joke(currentJokeIndex);

    while (1)
    {
        swiWaitForVBlank();

        scanKeys();
        u16 keys = keysDown();
        if (keys & KEY_A)
        {
            currentJokeIndex = (currentJokeIndex + 1) % (sizeof(jokes) / sizeof(jokes[0]));
            consoleClear();
            show_joke(currentJokeIndex);
        }
    }

    return 0;
}
