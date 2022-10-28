#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <3ds.h>

int main()
{
	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);

	printf("Welcome To FileDumper DevKit\n");
  printf("FileDumper v0");
  printf("Press A To See Available Dumer Options");
	printf("Press X To See SD Card Storage\n");
	printf("Press START to exit\n");

	while (aptMainLoop())
	{
		gspWaitForVBlank();
		gfxSwapBuffers();
		hidScanInput();

		u32 kDown = hidKeysDown();

		if (kDown & KEY_START)
			break;

		if (kDown & KEY_A) // If the A button got pressed, start the app launch
		{
        printf("Press L To Dump SystemNAND");
        printf("Press R To Dump MiiStudio[unfinished]");
        printf("Press B To Return To FileDumper Menu[unfinished]");
        printf("Press A To Create A Backup[Hasn't Been Implemented Yet!]");
        printf("Press X To Dump Game Card[unfinished]");
        if(kDown & KEY_L){
          printf("Dumping SystemNAND");
          printf("...");
          int msec = 0, trigger = 10;
          do{
            clock_t difference = clock() - before;
            msec = difference * 1000 / CLOCKS_PER_SEC;
            iterations++;
          }while(msec < trigger);
          printf("Time taken %d seconds %d milliseconds (%d iterations)\n",
          msec/1000, msec%1000, iterations); 
          printf("Finished!")
          printf("Press B To Return To Home Menu");
          if(kDown & KEY_B){
            break;
          }
        }
		}
	}

	gfxExit();
	return 0;
}
