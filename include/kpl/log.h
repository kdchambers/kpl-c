#pragma once

#include "kpl/common.h"
#include "kpl/string.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

static int kpl_string_from_i64(i64 value, char* buffer, int buffer_capacity);

typedef struct KplTextBuffer
{
    char* data;
    i32 count;
    i32 capacity;
} KplTextBuffer;

KplTextBuffer kpl_text_buffer_init(char* buffer, i32 buffer_size)
{
    const KplTextBuffer result = { .data = buffer, .count = 0, .capacity = buffer_size };
    return result;
}

void kpl_text_buffer_add_string(KplTextBuffer text_buffer, KplString string)
{
    //
    // Make sure we have enough space to write the string
    //
    assert((text_buffer.capacity - text_buffer.count) > string.len);

    int dst_i = text_buffer.count;
    for (int i = 0; i < string.len + 1; i++)
    {
        text_buffer.data[dst_i] = string.cstring[i];
        dst_i++;
    }
    text_buffer.count += string.len;
}

void kpl_text_buffer_add_nl(KplTextBuffer* text_buffer)
{
    const int i = text_buffer->count;
    text_buffer->data[i + 0] = '\n';
    text_buffer->data[i + 1] = '\0';
    text_buffer->count++;
}

void kpl_log(int fd, KplString string)
{
    const ssize_t bytes_written_count = write(fd, string.cstring, string.len);
    UNUSED(bytes_written_count);
}

void kpl_log_cstring(int fd, const char* string)
{
    const size_t string_len = strlen(string);
    const ssize_t bytes_written_count = write(fd, string, string_len);
    UNUSED(bytes_written_count);
}

int kpl_text_buffer_free_char_count(KplTextBuffer text_buffer)
{
    return (text_buffer.capacity - text_buffer.count) - 1;
}

KplTextBuffer kpl_text_buffer_reset(KplTextBuffer text_buffer)
{
    const KplTextBuffer result = { .data = text_buffer.data, .capacity = text_buffer.capacity, .count = 0 };
    return result;
}

void kpl_text_buffer_add_i64(KplTextBuffer* text_buffer, i64 value)
{
    int chars_written_count = kpl_string_from_i64(value, &text_buffer->data[text_buffer->count], 64);
    assert(chars_written_count > 0);
    text_buffer->count += chars_written_count;
}

static int kpl_string_from_i64(i64 value, char* buffer, int buffer_capacity)
{
    UNUSED(buffer_capacity); // TODO:

    const int temp_buffer_count = 16;
    int temp_buffer[temp_buffer_count];

    int x = value;
    int base = 10;
    int digit_index = 0;

    int buffer_index = 0;

    if (value < 0)
    {
        buffer[0] = '-';
        buffer_index = 1;
        x = x * -1;
    }

    while (x > 0)
    {
        temp_buffer[digit_index] = x % base;
        x = x / 10;
        digit_index++;
    }

    int count = digit_index;

    digit_index--;

    while (digit_index >= 0)
    {
        buffer[buffer_index] = (char) ('0' + temp_buffer[digit_index]);
        digit_index--;
        buffer_index++;
    }

    buffer[count] = '\0';
    return count;
}
