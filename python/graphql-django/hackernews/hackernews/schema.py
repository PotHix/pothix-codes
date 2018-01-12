import graphene

import links.schema
import users.schema


class Query(users.schema.Query, links.schema.Query, graphene.ObjectType):
    pass


class Mutation(users.schema.Mutation, links.schema.Mutation,
               graphene.ObjectType,):
    pass


schema = graphene.Schema(query=Query, mutation=Mutation)
