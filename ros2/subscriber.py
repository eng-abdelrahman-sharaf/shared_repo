import rclpy
from rclpy.node import Node

from std_msgs.msg import UInt16


class Subscriber(Node):

    def __init__(self):
        super().__init__('subscriber')
        self.subscription = self.create_subscription(
            UInt16,
            'topic',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):
        if msg.data < 5:
            self.get_logger().info(f'Obstacle detected at near distance {msg.data} rotating the robot')
        else :
            self.get_logger().info(f'No obstacle detected at distance {msg.data} moving the robot forward')


def main(args=None):
    rclpy.init(args=args)

    subscriber = Subscriber()

    rclpy.spin(subscriber)

    subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()