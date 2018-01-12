Playing with Python + Django + GraphQL
======================================

This code is based on
[this tutorial](https://www.howtographql.com/graphql-python/0-introduction/).

To setup:

```python
python3.6 -m venv venv
source venv/bin/activate
pip install django graphene graphene-django django-filter bpython
django-admin startproject hackernews
cd hackernews
python manage.py migrate
python manage.py runserver
```

The explorer should be available
at [http://localhost:8000/graphql](http://localhost:8000/graphql).
