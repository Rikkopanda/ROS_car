from setuptools import find_packages, setup

package_name = 'serial_motor_demo'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='rikverhoeven',
    maintainer_email='rikverhoeven10@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'driver = serial_motor_demo.driver:main',
            'gui = serial_motor_demo.gui:main',
        ],
    },
)
