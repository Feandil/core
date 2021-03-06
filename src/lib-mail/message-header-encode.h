#ifndef MESSAGE_HEADER_ENCODE_H
#define MESSAGE_HEADER_ENCODE_H

/* Encode UTF-8 input into output wherever necessary using either Q or B
   encoding depending on which takes less space (approximately). The encoded
   output is split into multiple lines if necessary (max 76 chars/line).
   Existing folding whitespace is preserved. Bare [CR]LF will be preserved by
   adding a TAB after it to make it a valid folding whitespace. All the control
   characters are encoded, including NUL, CR and LF. Sequences of one or more
   invalid UTF-8 characters are replaced by a single Unicode replacement
   character (U+fffd). */
void message_header_encode(const char *input, string_t *output);
void message_header_encode_data(const unsigned char *input, size_t len,
				string_t *output);

/* Encode the whole UTF-8 input using "Q" or "B" encoding into output.
   The output is split into multiple lines if necessary (max 76 chars/line).
   The first line's length is given as parameter. All the control characters
   are encoded, including NUL, CR and LF. Sequences of one or more invalid UTF-8
   characters are replaced by a single Unicode replacement character (U+fffd).
 */
void message_header_encode_q(const unsigned char *input, size_t len,
			     string_t *output, size_t first_line_len);
void message_header_encode_b(const unsigned char *input, size_t len,
			     string_t *output, size_t first_line_len);

#endif
