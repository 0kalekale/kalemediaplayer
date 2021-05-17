import setuptools

setuptools.setup(
    name="PyKmp", 
    version="0.1.0",
    author="kalekale",
    author_email="kalekale.anon@gmail.com",
    description="Python stuffs for KMP",
    url="https://github.com/0kalekale/kalemediaplayer",
    packages=setuptools.find_packages(),
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: GNU General Public License v3",
    ],
    install_requires=[
          'youtube_dl',
    ],
    python_requires='>=3.8',
)
