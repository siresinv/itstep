#See https://aka.ms/customizecontainer to learn how to customize your debug container and how Visual Studio uses this Dockerfile to build your images for faster debugging.

FROM mcr.microsoft.com/dotnet/aspnet:7.0 AS base
WORKDIR /app
EXPOSE 80
EXPOSE 443

FROM mcr.microsoft.com/dotnet/sdk:7.0 AS build
WORKDIR /src
COPY ["identity_postresql/identity_postresql.csproj", "identity_postresql/"]
RUN dotnet restore "identity_postresql/identity_postresql.csproj"
COPY . .
WORKDIR "/src/identity_postresql"
RUN dotnet build "identity_postresql.csproj" -c Release -o /app/build

FROM build AS publish
RUN dotnet publish "identity_postresql.csproj" -c Release -o /app/publish /p:UseAppHost=false

FROM base AS final
WORKDIR /app
COPY --from=publish /app/publish .
ENTRYPOINT ["dotnet", "identity_postresql.dll"]