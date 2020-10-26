# Lab 6  
**Record the IP address and the MAC address for the RPi.**
192.168.1.161  
B8:27:EB:C3:A8:8A  

### Try some Python code on the Pi

**How do you know what the shell script is doing?**

Opening the shell scripts in vi reveals them to fairly simply and readably import the respective tools and then call them with the desired text. Changing what they say is as simple as replacing the text in the call.

Adapt the scripts so that they say what you want them to say.

Now try the shellscripts in the ``speechToText`` directory.

These scripts use a program called [``vosk``](https://alphacephei.com/vosk/) to recognize numbers.

**How do we use ``vosk`` to recognize words and phrases?**  
First, we specify a list of words to be recognized. Then, we pass in the audio.  

**Include the output of vosk recognizing phrases you taught it to look for.**

```shell
{
  "result" : [{
      "conf" : 1.000000,
      "end" : 1.650000,
      "start" : 0.630000,
      "word" : "raspberry"
    }, {
      "conf" : 1.000000,
      "end" : 2.670000,
      "start" : 1.950000,
      "word" : "pie"
    }, {
      "conf" : 1.000000,
      "end" : 3.780000,
      "start" : 3.090000,
      "word" : "tasty"
    }],
  "text" : "raspberry pie tasty"
}
```


**Include the listing for a shell script and model files that you use to get vosk to recognize these phrases.**
```shell
arecord -D hw:2,0 -f cd -c1 -r 48000 -d 5 -t wav raspi.wav
python3 pi_words.py raspi.wav
```

## Connect the Arduino and the RPi

Connect your Arduino board to your RPi using a short USB cable.
Now, on the RPi, run the Arduino program:

```shell
pi@ixe00:~ $ arduino
```

Use the Arduino IDE to flash Blink onto the Arduino. Don’t forget to set the port!

Now, try adding a sensor and checking that you can read the value on the RPi using the Serial Monitor.

### Hello Pi, Hello Arduino

With your Pi and Arduino, try out the ``helloPi`` and ``helloArduino`` sketches. Tweak them to make them do something new.

``HelloPi.ino`` sets up the Arduino to say hello to the Pi repeatedly.
``HelloPi.py`` echos the Arduino’s message to the console in text form.
``sayHelloPi.py`` plays the helloPi.wav file whenever the Pi gets any message from the Arduino on the serialPort.

Flash the Arduino with ``HelloPi.ino``.
With ``HelloPi.ino`` running on the Arduino, run ``HelloPi.py`` on the Pi using ``$python HelloPi.py``.

**What would you change to make sayHelloPi say something else?**  
Change the audio file that it plays.

**How could you make it so that the Pi would only say something if the lights came on in the room?**  
You could either attach a sensor to the Arduino and only output the message if the lights are on, or attach a sensor to the RPi and only play audio if the lights are on.

**How could you make it so that the Pi would say different things based on different sensor values read by the Arduino?**  
Pass the sensor data from the Arduino to the RPi over serial, and have a simple if statement based on that data that depermines what is output.
## Your own voice agent

Program a simple application that understands different basic greetings (for example, Yo!, Good morning! And Good afternoon!) and responds either visibly, physically or auditorially in kind!

You are free to adapt this assignment to have the agent respond to any other set of vocabulary for any other purpose.

**Record someone trying out your design**

Using a phone or other video device, record someone trying out your GreetingBot. (This does not need to be an advertisement for your ChatBot; it is okay if the person is confused or asks questions or doesn't like it. We like the drama. Do not record someone using the default ChatBot.) Post the video to your README.md page!

**Submit your code to Github**

This project is going to be the submission of this week. You will need to upload the changes you made on the Pi to the GitHub page. To do that you need to follow three simple steps: Stage => Commit => Push!

[Uploading on github via terminal](https://docs.github.com/en/free-pro-team@latest/github/managing-files-in-a-repository/adding-a-file-to-a-repository-using-the-command-line)

```
$ git add .
# Adds the file to your local repository and stages it for commit. To unstage a file, use 'git reset HEAD YOUR-FILE'.

$ git commit -m "Add existing file"
# Commits the tracked changes and prepares them to be pushed to a remote repository. To remove this commit and modify the file, use 'git reset --soft HEAD~1' and commit and add the file again.

$ git push origin your-branch
# Pushes the changes in your local repository up to the remote repository you specified as the origin
```

You might be required to login in the terminal to your GitHub account. For more details on how the Git commands work or what other commands are available checkout this [cheatsheet](https://education.github.com/git-cheat-sheet-education.pdf).  


#### Pro-tips and other commands
`nano` is a general purpose text editor, so you can use it for any type of text file like the `.js`, `.html`, and `.css` files in this project.

Notice on the bottom of the terminal window that there is some text showing things like `^G Get Help` and `^O Write Out`. These are the commands that you can use in `nano`. The `^` character stands for `Ctrl`. So to `Write Out` (which means to save the file), you would type `Ctrl` and `O` (that's the letter `O`, not the number `0`). When you've typed these, you will see a bar appear at the bottom of the terminal that says `File Name to Write: chatServer.js`. This is the file name you are saving to. In this case, we want the same name, so we can just hit the `Enter` key. You will then see a message on the bottom that tells you how many lines were written, something like `[ Wrote 116 lines ]`.
