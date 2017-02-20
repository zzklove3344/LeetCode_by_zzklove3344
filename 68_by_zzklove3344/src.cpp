#include<stdio.h>
#include<stdlib.h>

int getCharLength(char *cArray)
{
	int length = 0;
	while (true)
	{
		if (!cArray[length])
			return length;
		else
			++length;
	}
	return length;
}

void findStart(char* cArray, int* pos)
{
	for (;; ++(*pos))
	{
		if (*pos == 0)
			return;
		else
		{
			if ((cArray[*pos] == ' ') && (cArray[*pos + 1] != ' '))
			{
				++(*pos);
				return;
			}
		}
	}
}

int findEnd(char* cArray, int pos)
{
	for (;; --pos)
		if (cArray[pos] != ' ')
			return pos;
}

void moveChar(char *cArray, int firstPos, int lastPos, int moveNum)
{
	if (moveNum == 0)
		return;
	else
	{
		int i = 0;
		for (i = lastPos;i >= firstPos; --i)
		{
			cArray[i + moveNum] = cArray[i];
			cArray[i] = ' ';
		}
	}
}


void adjustArray(char *cArray, int maxWidth, int wordNum, int spaceNum)
{
	if (cArray[maxWidth - 1] != ' ')
		return;
	if (wordNum == 0 || wordNum == 1)
		return;
	int i = 0, avergeSpace = spaceNum / (wordNum - 1);
	int remain = spaceNum - avergeSpace * (wordNum - 1);
	int* t1 = (int *)malloc((wordNum - 1) * sizeof(int));
	for (i = 0;i < (wordNum - 1);++i)
	{
		t1[i] = avergeSpace;
		if (remain > 0)
		{
			++t1[i];
			--remain;
		}
	}
	for (i = 0;i < maxWidth;++i)
		if (cArray[i] == ' ')
			break;
	int end = findEnd(cArray, maxWidth - 1), controll = 0;
	while (controll < (wordNum - 1))
	{
		findStart(cArray, &i);
		moveChar(cArray, i, end, t1[controll] - 1);
		end += t1[controll] - 1;
		i += t1[controll++] - 1;
	}
	free(t1);
}

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize)
{
	if (!words || wordsSize == 0)
		return NULL;
	int currentPosition = -1, i = 0, j = 0, k = 0;
	int *spaceNum = (int *)malloc(wordsSize * sizeof(int *)), *wordNum = (int *)malloc(wordsSize * sizeof(int *));
	char* s1 = (char *)malloc((maxWidth + 1) * sizeof(char));
	char** formatString = (char **)malloc(wordsSize * sizeof(char *));
	*returnSize = 1;
	wordNum[*returnSize - 1] = 0, spaceNum[*returnSize - 1] = 0;
	formatString[*returnSize - 1] = s1;
	while (i < wordsSize)
	{
		int temporaryLen = getCharLength(words[i]);
		if (temporaryLen == 0)
		{
			++i;
			continue;
		}
		if ((maxWidth - (currentPosition + 1)) >= temporaryLen)
		{
			for (j = 0;j < temporaryLen;++j)
				s1[++currentPosition] = words[i][j];
			s1[++currentPosition] = ' ';
			++i;
			++wordNum[*returnSize - 1];
		}
		else
		{
			spaceNum[*returnSize - 1] = wordNum[*returnSize - 1] + maxWidth - 1 - currentPosition;
			for (k = currentPosition;k < maxWidth;++k)
				s1[k] = ' ';
			s1[maxWidth] = '\0';
			s1 = (char *)malloc((maxWidth + 1) * sizeof(char));
			++*returnSize;
			formatString[*returnSize - 1] = s1;
			currentPosition = -1;
			wordNum[*returnSize - 1] = 0, spaceNum[*returnSize - 1] = 0;
		}
	}
	if (currentPosition == -1)
	{
		s1[++currentPosition] = ' ';
	}
	for (k = currentPosition;k < maxWidth;++k)
		s1[k] = ' ';
	s1[maxWidth] = '\0';
	for (i = 0;i < (*returnSize) - 1;++i)
		adjustArray(formatString[i], maxWidth, wordNum[i], spaceNum[i]);
	free(spaceNum);
	free(wordNum);
	return formatString;
}


int main(void)
{
	char* words[45] = { "Fourscore", "and", "seven", "years", "ago", "our", "fathers", "brought", "forth", "on", "this", "continent", "a", "new", "nation,", "conceived", "in", "liberty", "and", "dedicated", "to", "the", "proposition", "that", "all", "men", "are", "created", "equal.", "Now", "we", "are", "engaged", "in", "a", "great", "civil", "war,", "testing", "whether", "that", "nation", "or", "any", "nation"};


	char** s = NULL;
	int wordsSize = 45;
	int maxWidth = 50;
	int returnSize = 0;

	s = fullJustify(words, wordsSize, maxWidth, &returnSize);

	return 0;
}

//["Fourscore", "and", "seven", "years", "ago", "our", "fathers", "brought", "forth", "on", "this", "continent", "a", "new", "nation,", "conceived", "in", "liberty", "and", "dedicated", "to", "the", "proposition", "that", "all", "men", "are", "created", "equal.", "Now", "we", "are", "engaged", "in", "a", "great", "civil", "war,", "testing", "whether", "that", "nation", "or", "any", "nation", "so", "conceived", "and", "so", "dedicated", "can", "long", "endure.", "We", "are", "met", "on", "a", "great", "battlefield", "of", "that", "war.", "We", "have", "come", "to", "dedicate", "a", "portion", "of", "that", "field", "as", "a", "final", "resting-place", "for", "those", "who", "here", "gave", "their", "lives", "that", "that", "nation", "might", "live.", "It", "is", "altogether", "fitting", "and", "proper", "that", "we", "should", "do", "this.", "But", "in", "a", "larger", "sense,", "we", "cannot", "dedicate,", "we", "cannot", "consecrate,", "we", "cannot", "hallow", "this", "ground.", "The", "brave", "men,", "living", "and", "dead", "who", "struggled", "here", "have", "consecrated", "it", "far", "above", "our", "poor", "power", "to", "add", "or", "detract.", "The", "world", "will", "little", "note", "nor", "long", "remember", "what", "we", "say", "here,", "but", "it", "can", "never", "forget", "what", "they", "did", "here.", "It", "is", "for", "us", "the", "living", "rather", "to", "be", "dedicated", "here", "to", "the", "unfinished", "work", "which", "they", "who", "fought", "here", "have", "thus", "far", "so", "nobly", "advanced.", "It", "is", "rather", "for", "us", "to", "be", "here", "dedicated", "to", "the", "great", "task", "remaining", "before", "us--that", "from", "these", "honored", "dead", "we", "take", "increased", "devotion", "to", "that", "cause", "for", "which", "they", "gave", "the", "last", "full", "measure", "of", "devotion--that", "we", "here", "highly", "resolve", "that", "these", "dead", "shall", "not", "have", "died", "in", "vain,", "that", "this", "nation", "under", "God", "shall", "have", "a", "new", "birth", "of", "freedom,", "and", "that", "government", "of", "the", "people,", "by", "the", "people,", "for", "the", "people", "shall", "not", "perish", "from", "the", "earth."]
//80