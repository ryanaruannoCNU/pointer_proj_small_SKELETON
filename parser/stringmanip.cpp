#include <string.h>
#include "../includes/constants.h"
#include "../includes/stringmanip.h"


namespace KP{

	int amountOfMemoryToAllocateForNewString(int len_src, int numbTagsToReplace, int len_tag, int len_tag_replacement){
		return 1 + len_src + (numbTagsToReplace * (len_tag_replacement - len_tag));
	}

	int findNumbOccurrences(const char *src,  const char *tag) {
		if (src == NULL || tag == NULL) {
			return INVALID_NULL_PTR_DETECTED;
		}
		int src_len = strlen(src);
		int tag_len = strlen(tag);
		int cntr = 0;
		for (int i = 0; i < src_len; i++) {
			if (*(src + i) == tag[0] && strncmp((src + i), tag, tag_len) == 0) {
				cntr++;
			}
		}
		return cntr;
	}

	int replace(const char *src, char *new_src, const char *tag, const char *tag_replacement){
		if (src == NULL || tag == NULL || tag_replacement == NULL) {
			return INVALID_NULL_PTR_DETECTED;
		}
		int src_len = strlen(src);
		int tag_len = strlen(tag);
		int tag_replacement_len = strlen(tag_replacement);
		*new_src = new_src[amountOfMemoryToAllocateForNewString(src_len, findNumbOccurrences(src, tag), tag_len, tag_replacement_len)];
		int j = 0;
		for (int i = 0; i < src_len; i++) {
			if (*(src + i) == tag[0] && strncmp((src + i), tag, tag_len) == 0) {
				strncat((new_src + j), tag_replacement, tag_replacement_len);
				i += tag_len, j += tag_replacement_len;
				*(new_src + j) = *(src + i);
			}
		}
		return SUCCESS;
	}
}
