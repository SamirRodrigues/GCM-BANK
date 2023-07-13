FROM node:lts-alpine
WORKDIR /usr
COPY . .
RUN yarn 
EXPOSE 8080
WORKDIR /usr/src
CMD ["node", "app.js"]