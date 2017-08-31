#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main()
{
	FILE *file; 
	fopen_s(&file, "names.txt", "r");
	char name[35];
	int ans = 0;
	while (fscanf_s(file, "%35s", name, sizeof(name)) != EOF)
	{
		ans = Repeats(name);
		if (ans == 1)
		{
			printf("Hello %s, (yes)\n", name);
		}
		else
		{
			printf("Hello %s, (no)\n", name);
		}
	}
	fclose(file);
}

int Repeats(char name [])
{
	int size = strlen(name);
	for (int i = 0; i< (size-1); i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (toupper(name[j]) == toupper(name[i]))
			{
				return 1;
			}
		}
	}
	return 0;
}