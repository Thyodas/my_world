/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** interface -> TODO: add description
*/

#ifndef INTERFACE_H_
    #define INTERFACE_H_

    enum buttons_pos {
        BTN_BUCKET,
        BTN_GRID_SIZE,
        BTN_PEN_WIDTH,
        BTN_LEVEL,
        BTN_PICKER,/*
        BTN_SETTINGS,
        BTN_OPEN_FILE,
        BTN_SAVE_FILE,*/
        NB_BUTTON
    };

    #define NB_TOOL BTN_PICKER

    enum background_pos {
        BACKGROUND_TOOLS,/*
        BACKGROUND_SETTINGS,*/
        NB_BACKGROUND
    };

    enum mouse_state {
        IDLE,
        HOVERED,
        SELECTED
    };

    typedef struct {
        sfSprite *sprite;
        enum mouse_state state;
        bool is_visible;
        int (*on_click)();
    } button_t;

    typedef struct {
        sfSprite *sprite;
        enum mouse_state state;
        bool is_visible;
    } background_t;

    typedef struct {
        texture_data_t bucket;
        texture_data_t size;
        texture_data_t tools_bg;
        texture_data_t pen_width;
        texture_data_t level;
        texture_data_t picker;
        texture_data_t selected;
    } ui_textures;

    typedef struct {
        button_t buttons[NB_BUTTON];
        background_t backgrounds[NB_BACKGROUND];
        sfSprite *selected_sprite;
        sfRenderStates hover_state;
        sfRenderStates selected_state;
        ui_textures textures;
    } interface_t;

#endif /* INTERFACE_H_ */
