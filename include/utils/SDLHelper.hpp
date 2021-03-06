#ifndef SDLHELPER_HPP
#define SDLHELPER_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <switch.h>

/** @brief SDL helper functions to turn long repetitive actions in SDL into one-liners. */
namespace SDLHelper {
    /**
     * @brief Initialize all required/used parts of SDL
     * 
     * @return true if initialzation succeeded
     * @return false otherwise
     */
    bool initSDL();

    /**
     * @brief Clean up all initialized parts of SDL
     */
    void exitSDL();

    /**
     * @brief Clears the screen (renderer) with the specified colour
     * 
     * @param c color to clear with
     */
    void clearScreen(SDL_Color c);

    /**
     * @brief Create texture with given dimensions
     * 
     * @param w width of texture
     * @param h height of texture
     * @return created texture
     */
    SDL_Texture * createTexture(int w, int h);

    /**
     * @brief DestroyTexture wrapper
     * 
     * @param t texture to destroy
     */
    void destroyTexture(SDL_Texture * t);

    /**
     * @brief QueryTexture wrapper
     * 
     * @param t texture to query
     * @param w pointer to write width to
     * @param h pointer to write height to
     */
    void getDimensions(SDL_Texture * t, int * w, int * h);

    /**
     * @brief Get render offset
     * 
     * @param x pointer to write x-coordinate to
     * @param y pointer to write y-coordinate to
     */
    void getOffset(int * x, int * y);

    /**
     * @brief Set the offset of drawing operations
     * 
     * @param x x-coordinate of offset
     * @param y y-coordinate of offset
     */
    void setOffset(int x, int y);

    /**
     * @brief Emptys the font cache
     */
    void emptyFontCache();

    /**
     * @brief Set the font for future text rendering
     * 
     * @param p file path to font file
     */
    void setFont(std::string p);

    /**
     * @brief Reset renderer to screen
     */
    void renderToScreen();

    /**
     * @brief Set renderer to given texture
     * 
     * @param t texture to render to
     */
    void renderToTexture(SDL_Texture * t);

    /**
     * @brief Get the current texture blend mode
     * 
     * @return SDL_BlendMode 
     */
    SDL_BlendMode getBlendMode();

    /**
     * @brief Set the blend mode of drawn textures
     * 
     * @param b blend mode to set to
     */
    void setBlendMode(SDL_BlendMode b);

    /**
     * @brief Set the blend mode of draw operations (i.e. render to screen ops)
     * 
     * @param b blend mode to set to
     */
    void setRendererBlendMode(SDL_BlendMode b);

    // === DRAWING FUNCTIONS ===
    // -> Draw directly to the screen/renderer

    /**
     * @brief Update screen
     */
    void draw();

    /**
     * @brief Draw an ellipse with given diameters
     * 
     * @param c color to draw with
     * @param x x-coordinate of drawing start position
     * @param y y-coordinate of drawing start position
     * @param w x-diamater of eclipse
     * @param h y-diamater of eclipse
     */
    void drawEllipse(SDL_Color c, int x, int y, unsigned int w, unsigned int h);

    /**
     * @brief Draw a filled rectangle with the given dimensions
     * 
     * @param c color to draw with
     * @param x x-coordinate of drawing start position
     * @param y y-coordinate of drawing start position
     * @param w width of rectangle
     * @param h height of rectangle
     */
    void drawFilledRect(SDL_Color c, int x, int y, int w, int h);

    /**
     * @brief Draw a filled rounded rectangle with the given values
     * 
     * @param c color to draw with
     * @param x x-coordinate of drawing start position
     * @param y y-coordinate of drawing start position
     * @param w width of rectangle
     * @param h height of rectangle
     * @param r corner radius
     */
    void drawFilledRoundRect(SDL_Color c, int x, int y, int w, int h, unsigned int r);

    /**
     * @brief Draw a rounded rectangle (outline) with given border size
     * 
     * @param c color to draw with
     * @param x x-coordinate of drawing start position
     * @param y y-coordinate of drawing start position
     * @param w width of rectangle
     * @param h height of rectangle
     * @param r corner radius
     * @param b border thickness (in pixels)
     */
    void drawRoundRect(SDL_Color c, int x, int y, int w, int h, unsigned int r, unsigned int b);

    /**
     * @brief Draw a rectangle (outline) with given border size
     * 
     * @param c color to render with
     * @param x x-coordinate of drawing start position
     * @param y y-coordinate of drawing start position
     * @param w width of rectangle
     * @param h height of rectangle
     * @param b border thickness (in pixels)
     */
    void drawRect(SDL_Color c, int x, int y, int w, int h, unsigned int b);

    /**
     * @brief Draw provided texture at specified coordinates tinted with given colour
     * 
     * @param tex pointer of rendered texture to draw
     * @param c colour to tint with
     * @param x texture offset x-coordinate
     * @param y texture offset y-coordinate
     * @param w texture width
     * @param h texture height
     * @param tx mask offset x-coordinate
     * @param ty mask offset y-coordinate
     * @param tw mask width
     * @param th mask height
     */
    void drawTexture(SDL_Texture * tex, SDL_Color c, int x, int y, int w = -1, int h = -1, int tx = -1, int ty = -1, int tw = -1, int th = -1);

    // === RENDERING FUNCTIONS ===
    // -> Draw to a texture and return it
    // -> The caller must destroy the texture

    // Simply changes target to texture and then calls draw...() with white colour

    /**
     * @brief Renders an eclipse
     * 
     * @param xd x-diamater of eclipse
     * @param yd y-diamater of eclipse
     * @return pointer to rendered texture
     */
    SDL_Texture * renderEllipse(unsigned int xd, unsigned int yd);

    /**
     * @brief Renders a filled corner rectangle
     * 
     * @param w width of rectangle
     * @param h height of rectangle
     * @return pointer to rendered texture
     */
    SDL_Texture * renderFilledRect(int w, int h);

    /**
     * @brief Renders a filled rounded corner rectangle
     * 
     * @param w width of rectangle
     * @param h height of rectangle
     * @param c corner radius
     * @return pointer to rendered texture
     */
    SDL_Texture * renderFilledRoundRect(int w, int h, unsigned int c);

    /**
     * @brief Renders a rounded corner rectangle
     * 
     * @param w width of rectangle
     * @param h height of rectangle
     * @param r corner radius
     * @param b border thickness
     * @return pointer to rendered texture
     */
    SDL_Texture * renderRoundRect(int w, int h, unsigned int r, unsigned int b);

    /**
     * @brief Renders a basic rectangle
     * 
     * @param w width of rectangle
     * @param h height of rectangle
     * @param b border thickness
     * @return pointer to rendered texture
     */
    SDL_Texture * renderRect(int w, int h, unsigned int b);

    /**
     * @brief Renders image from image path
     * 
     * @param path file path to image
     * @return pointer to rendered texture
     */
    SDL_Texture * renderImage(std::string path);

    /**
     * @brief Renders image from image pointer and image size
     * 
     * @param ptr pointer to image
     * @param size image size
     * @return pointer to rendered texture
     */
    SDL_Texture * renderImage(u8 * ptr, size_t size);

    /**
     * @brief Renders image shrinked from image pointer and image size
     * 
     * @param ptr pointer to image
     * @param size image size
     * @param xF shrink factor for x-coordinate
     * @param yF shrink factor for y-coordinate
     * @return pointer to rendered texture
     */
    SDL_Texture * renderImageShrinked(u8 * ptr, size_t size, int xF, int yF);

    /**
     * @brief Renders text
     * @note Always drawn in white!
     * 
     * @param str text to render
     * @param font_size font size to render width in
     * @param style font style to render with
     * @return pointer to rendered texture
     */
    SDL_Texture * renderText(std::string str, int font_size, int style = TTF_STYLE_NORMAL);

    /**
     * @brief Renders text with specified width
     * 
     * @param str text to render
     * @param font_size font size to render width in
     * @param max_w max width to render in
     * @param style font style to render with
     * @return pointer to rendered texture
     */
    SDL_Texture * renderTextWrapped(std::string str, int font_size, uint32_t max_w, int style = TTF_STYLE_NORMAL);
};

#endif