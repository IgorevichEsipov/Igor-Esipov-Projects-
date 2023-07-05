import turtle as t
import os
import random

window = t.Screen()
window.title("The Pong Game")
window.bgcolor("black")
window.setup(width=800, height=600)
window.tracer(0)

player_a_score = 0
player_b_score = 0
game_mode = None

left_paddle = t.Turtle()
left_paddle.speed(0)
left_paddle.shape("square")
left_paddle.color("white")
left_paddle.shapesize(stretch_wid=5, stretch_len=1)
left_paddle.penup()
left_paddle.goto(-350, 0)

right_paddle = t.Turtle()
right_paddle.speed(0)
right_paddle.shape("square")
right_paddle.color("white")
right_paddle.shapesize(stretch_wid=5, stretch_len=1)
right_paddle.penup()
right_paddle.goto(350, 0)

ball = t.Turtle()
ball.speed(0)
ball.shape("circle")
ball.color("white")
ball.penup()
ball.goto(0, 0)
ball_dx = 0.2
ball_dy = 0.2

score_pen = t.Turtle()
score_pen.speed(0)
score_pen.color("white")
score_pen.penup()
score_pen.hideturtle()
score_pen.goto(0, 260)
score_pen.write("Player A: 0  Player B: 0", align="center", font=('Arial', 24, 'normal'))

stripe = t.Turtle()
stripe.speed(0)
stripe.color("white")
stripe.penup()
stripe.goto(0, 300)
stripe.pendown()
stripe.goto(0, -300)

menu = t.Turtle()
menu.speed(0)
menu.color("white")
menu.penup()
menu.hideturtle()
menu.goto(0, 220)
menu.write("Select game mode:", align="center", font=('Arial', 18, 'normal'))
menu.goto(0, 190)
menu.write("1 - Human vs Human", align="center", font=('Arial', 16, 'normal'))
menu.goto(0, 160)
menu.write("2 - Human vs CPU", align="center", font=('Arial', 16, 'normal'))


def start_game():
    global game_mode
    game_mode = "Human vs Human" if menu_input == 1 else "Human vs CPU"
    menu.clear()
    window.update()


menu_input = None

while menu_input is None:
    window.update()
    menu_input = window.numinput("Menu", "Enter your selection:", minval=1, maxval=2)

start_game()


def set_game_mode(mode):
    global game_mode
    game_mode = mode
    menu.clear()


def move_left_paddle_up():
    y = left_paddle.ycor()
    if y < 250:
        y += 20
    left_paddle.sety(y)


def move_left_paddle_down():
    y = left_paddle.ycor()
    if y > -240:
        y -= 20
    left_paddle.sety(y)


def move_right_paddle_up():
    y = right_paddle.ycor()
    if y < 250:
        y += 20
    right_paddle.sety(y)


def move_right_paddle_down():
    y = right_paddle.ycor()
    if y > -240:
        y -= 20
    right_paddle.sety(y)


window.listen()
window.onkeypress(move_left_paddle_up, 'w')
window.onkeypress(move_left_paddle_down, 's')
window.onkeypress(move_right_paddle_up, 'Up')
window.onkeypress(move_right_paddle_down, 'Down')
window.onkeypress(lambda: set_game_mode(1), '1')
window.onkeypress(lambda: set_game_mode(2), '2')


def reset_game():
    global player_a_score, player_b_score
    player_a_score = 0
    player_b_score = 0
    score_pen.clear()
    score_pen.write("Player A: 0  Player B: 0", align="center", font=('Arial', 24, 'normal'))
    ball.goto(0, 0)
    ball_dx = 0.2 if game_mode == "Human vs Human" else 0.15
    ball_dy = 0.2
    window.onkeypress(None, 'r')  # Disable 'r' key press event


def game_over():
    menu.goto(0, 0)
    menu.write("Game Over", align="center", font=('Arial', 24, 'normal'))
    menu.goto(0, -30)
    menu.write("Press 'R' to play again", align="center", font=('Arial', 24, 'normal'))
    window.onkeypress(reset_game, 'r')  # Enable 'r' key press event for game restart


def ai_move():
    y = right_paddle.ycor()

    # Add a random offset to the AI's paddle movement
    random_offset = random.randint(-20, 20)
    target_y = ball.ycor() + random_offset

    # Limit the AI's movement within the boundaries
    if target_y > 250:
        target_y = 250
    elif target_y < -240:
        target_y = -240

    # Move the AI's paddle towards the target y position
    if y < target_y:
        y += 1
    elif y > target_y:
        y -= 1
    right_paddle.sety(y)


while True:
    window.update()

    if game_mode is not None:
        ball.setx(ball.xcor() + ball_dx)
        ball.sety(ball.ycor() + ball_dy)

        if ball.ycor() > 290:
            ball.sety(290)
            ball_dy *= -1
        elif ball.ycor() < -290:
            ball.sety(-290)
            ball_dy *= -1

        if ball.xcor() > 390:
            ball.goto(0, 0)
            ball_dx *= -1
            player_a_score += 1
            score_pen.clear()
            score_pen.write("Player A: {}  Player B: {}".format(player_a_score, player_b_score),
                            align="center", font=('Arial', 24, 'normal'))
            os.system("afplay wallhit.wav&")

        elif ball.xcor() < -390:
            ball.goto(0, 0)
            ball_dx *= -1
            player_b_score += 1
            score_pen.clear()
            score_pen.write("Player A: {}  Player B: {}".format(player_a_score, player_b_score),
                            align="center", font=('Arial', 24, 'normal'))
            os.system("afplay wallhit.wav&")

        if (340 > ball.xcor() > 330) and (right_paddle.ycor() - 50 < ball.ycor() < right_paddle.ycor() + 50):
            ball.setx(330)
            ball_dx *= -1
            os.system("afplay paddle.wav&")

        elif (-340 < ball.xcor() < -330) and (left_paddle.ycor() - 50 < ball.ycor() < left_paddle.ycor() + 50):
            ball.setx(-330)
            ball_dx *= -1
            os.system("afplay paddle.wav&")

        if game_mode == "Human vs CPU":
            ai_move()

        if player_a_score == 5 or player_b_score == 5:
            game_over()