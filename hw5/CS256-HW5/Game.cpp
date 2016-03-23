// Cristian Avina Lopez
// Homework 5
// Completed 3/12/16

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <SDL2/SDL.h>

#include "Game.h"

Game::Game() 
    : width(DEFAULT_WIDTH), height(DEFAULT_HEIGHT), 
      start(0), last(0), current(0), 
      good(true), running(false), 
      particles(std::vector<Particle>())
{
    // Seed the random number generator
    srand(time(0));
    
    // initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        good = false;
        return;
    }
    
    // initialize SDL window
    window = SDL_CreateWindow("Gravity", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        good = false;
        return;
    }
    
    // initialize SDL renderer
    renderer = SDL_CreateRenderer(window, -1, 
            SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        good = false;
        return;
    }
    
    // initialize particle texture
    SDL_Surface* bmp = SDL_LoadBMP("particle.bmp");
    if (bmp == NULL)
    {
        good = false;
        return;
    }
    particleTexture = SDL_CreateTextureFromSurface(renderer, bmp);
    SDL_FreeSurface(bmp);
    if (particleTexture == NULL)
    {
        good = false;
        return;
    }
    
    // initialize our particles
    for (int i = 0; i < PARTICLE_COUNT; ++i)
    {
        particles.push_back(randomParticle());
    }
}

Game::~Game()
{
    if (!good)
    {
        std::cout << "SDL Error: " << SDL_GetError() << std::endl;
    }
    if (particleTexture != NULL)
    {
        SDL_DestroyTexture(particleTexture);
    }
    if (renderer != NULL)
    {
        SDL_DestroyRenderer(renderer);
    }
    if (window != NULL)
    {
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
}

int Game::operator()()
{
    if (!good)
    {
        return -1;
    }
    running = true;
    SDL_Event event;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    start = SDL_GetTicks();
    last = start;

    while (running) 
    // every iteration is 1 frame
    {
        current = SDL_GetTicks();
        while (SDL_PollEvent(&event))
        {
            handleEvent(event);
        }
        update((current - last) / 1000.0);
        render();
        last = current;
    }

    return 0;
}

// dt is time since last frame in seconds
void Game::update(double dt)
{
    double velocityX, velocityY;
    std::cout << dt << " sec since last frame.\n";

    for ( int i = 0; i < PARTICLE_COUNT; i++ ){
        Particle& firstParticle = particles[i];
        for ( int j = 0; j < PARTICLE_COUNT; j++ ){
            Particle& particleTwo = particles[j];

            if (i != j){
                //acceleration...
                double acceleration = G * (particleTwo.getMass() / (pow(firstParticle.getRadius(),2)));
                //Delta x & Delta y
                double deltaX = (particleTwo.getPos().getX() - firstParticle.getPos().getX());
                double deltaY = (particleTwo.getPos().getY() - firstParticle.getPos().getY());
                //Arc Tan
                double arctanXY= atan2(deltaX,deltaY);
                //Sin & Cos
                double Xinput = sin(arctanXY);
                double Yinput = cos(arctanXY);
                //Veloctiy X, Veloctiy Y
                velocityX = Xinput * (dt/10000) * acceleration;
                velocityY = Yinput * (dt/10000) * acceleration;
                //First particle velocity
                firstParticle.setVelocity(firstParticle.getVelocity().getX() + velocityX , firstParticle.getVelocity().getY() + velocityY);
            }
        }
    }
    // Replace with your game logic!
    for ( int i = 0; i < PARTICLE_COUNT; i++ ){
        Particle& p = particles[i];
        p.positionChange();
    }


        for ( int i = 0; i < PARTICLE_COUNT; i++ )
    {
        for ( int j = 0; j < PARTICLE_COUNT; j++ )
        {

            double positionOfDeltaX = particles[j].getPos().getX() - particles[i].getPos().getX(); // Position DX
            double positionOfDeltaY = particles[j].getPos().getY() - particles[i].getPos().getY(); // Position DY
            double distance = sqrt(pow(positionOfDeltaX, 2) + pow(positionOfDeltaY, 2)); 
            //distance between particles
            if ((i < j) && distance <= particles[i].getRadius() + particles[j].getRadius())
            {
                double velocity1 = sqrt(pow(particles[i].getVelocity().getX(), 2) + pow(particles[i].getVelocity().getY(), 2));
                double velocity2 = sqrt(pow(particles[j].getVelocity().getX(), 2) + pow(particles[j].getVelocity().getY(), 2));
                //Mass
                double mass1 = particles[i].getMass();
                double mass2 = particles[j].getMass();
                //Tangents
                double tangent1 = atan2(particles[i].getVelocity().getX(), particles[i].getVelocity().getY());
                double tangent2 = atan2(particles[j].getVelocity().getX(), particles[j].getVelocity().getY());
                //PHI Angle
                double PHI = atan2(positionOfDeltaX, positionOfDeltaY);
                //X & Y Velocity
                double xVelocity1 = (((((velocity1 * cos(tangent1 - PHI) * (mass1 - mass2)) + (2 * mass2 * velocity2 * cos(tangent2 - PHI)))/(mass1 + mass2)) * cos(PHI))+ (velocity1 * sin(tangent1 - PHI) * cos(PHI - (PI/2))));
                double yVelocity1 = (((((velocity1 * cos(tangent1 - PHI) * (mass1 - mass2)) + (2 * mass2 * velocity2 * cos(tangent2 - PHI)))/(mass1 + mass2)) 
                    * sin(PHI))+ (velocity1 * sin(tangent1 - PHI) * sin(PHI - (PI/2))));
                //X & Y Velocity
                double xVelocity2 = (((((velocity2 * cos(tangent2 - PHI) * (mass2 - mass1)) + (2 * mass1 * velocity1 * cos(tangent1 - PHI)))/(mass1 + mass2)) 
                    * cos(PHI))+ (velocity2 * sin(tangent2 - PHI) * cos(PHI - (PI/2))));
                double yVelocity2 = (((((velocity2 * cos(tangent2 - PHI) * (mass2 - mass1)) + (2 * mass1 * velocity1 * cos(tangent1 - PHI)))/(mass1 + mass2)) 
                    * sin(PHI))+ (velocity2 * sin(tangent2 - PHI) * sin(PHI - (PI/2))));

                //Set Velocity
                particles[i].setVelocity(xVelocity1, yVelocity1);
                particles[j].setVelocity(xVelocity2, yVelocity2);
            }     
        }
    }
        //Wall Bouncing 
        for ( int i = 0; i < PARTICLE_COUNT; i++ ){
        Particle& p = particles[i];
        if(p.getPos().getY() + p.getPos().getY() < 0){
            p.setVelocity(p.getVelocity().getX(), p.getVelocity().getY()*-1); 
        }
        if(p.getPos().getY() + p.getVelocity().getY() >600){
            p.setVelocity(p.getVelocity().getX(), p.getVelocity().getY()*-1);
        }
        if((p.getPos().getX() + p.getVelocity().getX()) < 0){
            p.setVelocity(-1*p.getVelocity().getX(), p.getVelocity().getY());
        }
        if(p.getPos().getX() + p.getVelocity().getX() > 800){
            p.setVelocity(-1*p.getVelocity().getX(), p.getVelocity().getY());
        }
        p.positionChange();
    }
}

void Game::render()
{
    SDL_RenderClear(renderer);
    
    // rendering here would place objects beneath the particles
    
    for (const Particle& p : particles)
    {
        drawParticle(p);
    }
    
    // rendering here would place objects on top of the particles
    
    SDL_RenderPresent(renderer);
}

void Game::handleEvent(const SDL_Event& event)
{
    switch (event.type)
    {
    // Add your own event handling here if desired
    case SDL_QUIT:
        running = false;
        break;
    default:
        break;
    }
}

void Game::drawParticle(const Particle& p)
{
    SDL_Rect dst;
    double shift = p.getRadius();
    dst.x = (int) (p.getPos().getX() - shift);
    dst.y = (int) (p.getPos().getY() - shift);
    dst.w = shift * 2;
    dst.h = shift * 2;
    SDL_RenderCopy(renderer, particleTexture, NULL, &dst);
}

Particle Game::randomParticle() const
{
    Point pos(rand() % width, rand() % height);
    
    // using random percentage of MAX_MASS
    double mass = ((double) rand() / RAND_MAX) * MAX_MASS + 1.0;
    
    return Particle(pos, mass);
}
