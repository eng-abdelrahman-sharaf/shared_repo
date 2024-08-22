import rclpy
from rclpy.node import Node

from std_msgs.msg import UInt16
from random  import randint

class Publisher(Node):

    def __init__(self):
        super().__init__('publisher')
        self.publisher_ = self.create_publisher(UInt16, 'topic', 10)
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)

    def timer_callback(self):
        msg = UInt16()
        msg.data = randint(2 , 400)
        self.publisher_.publish(msg)
        self.get_logger().info(f'Publishing sensor measurements [{msg.data}]')


def main(args=None):
    rclpy.init(args=args)

    publisher = Publisher()

    rclpy.spin(publisher)

    publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()