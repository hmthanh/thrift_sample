from MultiplicationService import *                                                   
                                                                                      
class MultiplicationHandler(Iface):                                                   
    def multiply(self, n1, n2):                                                       
        print("Server has received a multiplication request: {} x {}.".format(n1, n2))
        return n1 * n2
