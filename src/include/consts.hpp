#ifndef _CONSTS_HPP_
#define _CONSTS_HPP_

// For menu
enum {
	win_w = 600,
	win_h = 600,

	btn_w = 150,
	btn_h = 50
};

// For core
enum {
	// Window setup
	window_w = 600,
	window_h = 600,

	// Field setup
	field_w = 19,
	field_h = 20,
	field_x_offset = 120,
	field_y_offset = 100,

	// Rect of field
	rect_size = 20,

	// Snake setup
	snake_start_length = 3,
	snake_max_length = 100,

	// Tile map setup
	tile_block_w = 18,
	tile_block_h = 18,
	tile_total_blocks = 8,

	// Labeles setup
	// Score counter text
	score_buffer_size = 4,
	score_text_size = 43,
	score_text_x = 178, score_text_y = 520,

	// Game over text
	lose_text_size = 43,
	lose_text_x = 175, lose_text_y = 300,

	// Sounds
	music_volume = 10,
	byte_volume = 50
};


#endif
