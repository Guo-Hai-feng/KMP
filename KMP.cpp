#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	vector<int>Arry(string pattern)
	{
		int index = 0;
		vector<int> arry(pattern.size(), 0);
		for (int i = 1; i < pattern.size();)
		{
			if (pattern[i] == pattern[index])
			{
				arry[i] = index + 1;
				index++;
				i++;
			}
			else
			{
				if (index != 0)
				{
					index = arry[index - 1];
				}
				else
				{
					arry[i] = 0;
					i++;
				}
			}
		}
		return arry;

	}
	int KMP(string text, string pattern)
	{
		vector<int>arry = Arry(pattern);

		int i = 0, j = 0;
		while (i < text.size() && j < pattern.size())
		{
			if (text[i] == pattern[j])
			{
				i++;
				j++;
			}
			else
			{
				if (j != 0)
				{
					j = arry[j - 1];
				}
				else
				{
					i++;
				}
			}
		}
		if (j == pattern.size())
		{
			return i - pattern.size();
		}
		else
		{
			return -1;
		}
	}
	int strStr(string haystack, string needle) {
		return  KMP(haystack, needle);

	}
};
