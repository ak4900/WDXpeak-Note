try:
    from setuptools import setup
except ImportError:
    from distutils.core import setup

config = {
    'description': 'My Project',
    'author': 'wdxtub',
    'url': 'http://www.wdxtub.com',
    'download_url': 'http://www.wdxtub.com',
    'author_email': 'wdxtub@qq.com',
    'version': '0.1',
    'install_requires': ['nose'],
    'packages': ['NAME'],
    'scripts': [],
    'name': 'projectname'
}

setup(**config)
