SRC += num_word.c

VIA_ENABLE = yes
COMBO_ENABLE = yes
NKRO_ENABLE = yes
STENO_ENABLE = yes
STENO_PROTOCOL = geminipr
MIDI_ENABLE = yes


OPT_DEFS += -DUSER_NUM_WORD_ENABLE
SRC += process_records.c
