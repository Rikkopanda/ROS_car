from setuptools import find_packages, setup

package_name = 'kimbo_control_dc_motor'

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
			"test_node_exec = kimbo_control_dc_motor.my_first_node:main",
            "make_turtle_circle = kimbo_control_dc_motor.draw_circle:main",
        ],
    },
)
