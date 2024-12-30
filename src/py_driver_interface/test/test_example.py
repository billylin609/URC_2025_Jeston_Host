import unittest

# Use full command
# colcon test --event-handlers console_direct+

class TestDummy(unittest.TestCase):
    def test_dummy(self):
        assert True
