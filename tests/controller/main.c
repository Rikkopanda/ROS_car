
#include "joystick.h"
#include "stdio.h"
#include <malloc.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <arpa/inet.h> /* for htonl, etc. */

#define DEV_INPUT_JS0 NULL
#define RIGHT_FROM_TOUCH_PAD_BUTTON_INDEX 9

static int joystick_fd;

void print1(struct js_event *jse)
{
	printf("time:%d\tvalue:%d\te_type:%c\taxis/button num:%d\n",
		jse->time, jse->value, jse->type, jse->number);
}

void print2(struct wwvi_js_event *jse)
{
	if (jse == NULL)
	{
		printf("jse == NULL\n ");
		return ;
	}
	if (jse->stick_x == -1 && jse->stick_x == -1)
	{
		int one_true = 0;
		for (int i = 0; i <= 10; i++)
		{
			if (jse->button[i] == 1)
			{
				one_true = 1;
			}
		}
		if (one_true == 0)
			return ;
	}
	printf("button[11]: ");
	for (int i = 0; i <= 10; i++)
	{
		printf("%d,", jse->button[i]);
	}
	printf(" stick_x:%d\tstick_y:%d\n",
		jse->stick_x, jse->stick_y);
}

/* These are sensible on Logitech Dual Action Rumble and xbox360 controller. */
static int joystick_x_axis;
static int joystick_y_axis;

int main(void)
{
	joystick_fd = open_joystick(DEV_INPUT_JS0);
	
	static struct wwvi_js_event jse;
	int			rc;

	while (1)
	{
		memset(&jse.button[0], 0, sizeof(jse.button[0]*10));
		jse.stick_x = -1;
		jse.stick_y = -1;
		// sleep(1);
		rc = get_joystick_status(&jse);
		print2(&jse);
		if (rc != 0)
			continue;
		else if (jse.button[9] == 1)
		{
			printf("closing joystick...\n");
			close_joystick();
			break;
		}
	}
	printf("exiting...\n");
}