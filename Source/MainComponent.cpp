#include "MainComponent.h"

//==============================================================================
// STEP 2
// Initialize constructor with a string name (button) (an initializer list)
MainComponent::MainComponent() : openButton("Open")
{
    setSize (200, 100);
    // no input channels, so set to 0
    setAudioChannels (0, 2);
    
    //STEP 4
    // Capture event when button is clicked using lambda
    // call function when clicked
    openButton.onClick = [this] { openButtonClicked(); };
    
    // Add as a child component of MainComponent
    addAndMakeVisible(&openButton);
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//STEP 5
void MainComponent::openButtonClicked()
{
    DBG("clicked"); // when open button is clicked, will console out "clicked"
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    // This function will be called when the audio device is started, or when
    // its settings (i.e. sample rate, block size, etc) are changed.

    // You can use this function to initialise any resources you might need,
    // but be careful - it will be called on the audio thread, not the GUI thread.

    // For more details, see the help for AudioProcessor::prepareToPlay()
}

void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    // Your audio-processing code goes here!

    // For more details, see the help for AudioProcessor::getNextAudioBlock()

    // Right now we are not producing any data, in which case we need to clear the buffer
    // (to prevent the output of random noise)
    bufferToFill.clearActiveBufferRegion();
}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    // You can add your drawing code here!
}

void MainComponent::resized()
{
    // STEP 3
    //Set bounds
    openButton.setBounds(10, 10, getWidth() -20, 30);
}
