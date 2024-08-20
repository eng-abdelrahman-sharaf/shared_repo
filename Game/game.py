import random
class Game:
    def __init__(self):
        self.__scores = [0,0] 

    def __gen_trial(self):
        return (random.randint(1,3) , random.randint(1,3))
    
    def __get_winner(self, trial: tuple):
        if trial[0] == trial[1]:
            return -1
        match trial:
            case (1,2):
                return 1
            case (1,3):
                return 0
            case (2,1):
                return 0
            case (2,3):
                return 1
            case (3,1):
                return 1
            case (3,2):
                return 0
            
    def main_loop(self):
        for _ in range(4):
            winner = self.__get_winner(self.__gen_trial())
            if winner != -1:
                self.__scores[winner] += 1
        print( "max score : " , max(self.__scores))
        if self.__scores[0] != self.__scores[1]:
            print("winner : ", "player 1" if self.__scores[0] > self.__scores[1] else "player 2" ," with score : ", max(self.__scores), sep='')
        else:
            print("no winner")
        print("player 1 score : ", self.__scores[0])
        print("player 2 score : ", self.__scores[1])
