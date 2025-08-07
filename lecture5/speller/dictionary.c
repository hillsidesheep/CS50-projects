// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26 * 26;
// const unsigned int N = 26;

// Hash table
node *table[N];

// 全局变量：记录词典中的单词总数
static unsigned word_count = 0;  // 关键：用于统计单词数量

// 辅助函数：忽略大小写比较两个字符串
static bool strcaseeq(const char *a, const char *b)
{
    while (*a && *b)
    {
        if (tolower(*a) != tolower(*b))
        {
            return false;
        }
        a++;
        b++;
    }
    // 确保两个字符串同时结束
    return *a == '\0' && *b == '\0';
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    if (word == NULL)
    {
        return false;
    }

    unsigned int index = hash(word);
    node *current = table[index];

    while (current != NULL)
    {
        if (strcaseeq(current->word, word))
        {
            return true;
        }
        current = current->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // return toupper(word[0]) - 'A';

    // 处理空字符串
    if (word == NULL || *word == '\0')
        return 0;

    // 取第一个字符并转换为0-25范围
    int first = toupper(word[0]) - 'A';
    first = (first < 0 || first >= 26) ? 0 : first;  // 确保在有效范围内

    // 处理第二个字符，若不存在则视为'A'
    int second = 0;  // 默认值，相当于'A'
    if (word[1] != '\0')
    {
        second = toupper(word[1]) - 'A';
        second = (second < 0 || second >= 26) ? 0 : second;  // 确保在有效范围内
    }

    // 计算哈希值
    return first * 26 + second;
}

// To insert the lowercase of the word.
bool insert(char *word)
{
    if (word == NULL)
    {
        return false;
    }

    unsigned int index = hash(word);

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return false;
    }

    // 复制单词到节点（确保存储的是小写形式）
    for (int i = 0; word[i]; i++)
    {
        n->word[i] = tolower((unsigned char)word[i]);  // 转换为小写
    }
    n->word[strlen(word)] = '\0';  // 确保字符串结束符

    n->next = table[index];
    table[index] = n;
    return true;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    word_count = 0;

    if (dictionary == NULL)
    {
        return false;
    }

    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) == 1)
    {
        if (insert(word))
        {
            word_count++;
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *ptr = table[i];
        while (ptr != NULL)
        {
            node *temp = ptr->next;
            free(ptr);
            ptr = temp;
        }
        table[i] = NULL;
    }
    return true;
}
